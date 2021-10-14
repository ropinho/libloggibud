#include <iostream>
#include <string>
#include <loggibud/json/conversors.hpp>
#include <loggibud/point.h>
#include <rapidjson/document.h>

int main(int argc, char const *argv[])
{
    const char* jsonString = "{\"point\":{\"lng\":2.0,\"lat\":1.0}}";
    std::cout << jsonString << std::endl;

    rapidjson::Document doc;
    doc.Parse(jsonString);

    auto& pointValue = doc["point"];
    auto point = bud::to_point(pointValue);

    std::cout << "Longitude: " << point.lng << std::endl;
    std::cout << "Latitude: " << point.lat << std::endl;

    return 0;
}
