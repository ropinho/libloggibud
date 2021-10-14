#include <iostream>
#include <string>
#include <rapidjson/document.h>
#include <loggibud/json/conversors.hpp>
#include <loggibud/delivery.h>

int main(int argc, char const *argv[])
{
    const char* jsonString = "{\"delivery\":{\"id\":\"0123456abcdef\",\"point\":{\"lng\":2.0,\"lat\":1.0},\"size\":180}}";
    std::cout << jsonString << std::endl;

    rapidjson::Document doc;
    doc.Parse(jsonString);

    auto& deliveryValue = doc["delivery"];
    bud::Delivery delivery = bud::to_delivery(deliveryValue);

    std::cout << "ID: " << delivery.id << std::endl;
    std::cout << "Point: ("
              << delivery.point.lng << ", "
              << delivery.point.lat << ")" 
              << std::endl;
    std::cout << "Size: " << delivery.size << std::endl;

    return 0;
}
