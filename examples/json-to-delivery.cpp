/**
 * Copyright 2021 <Ronaldd Pinho>
 */
#include <loggibud/delivery.h>
#include <rapidjson/document.h>
#include <loggibud/json/conversors.h>

#include <iostream>
#include <string>

int main() {
  const char* jsonString =
      "{\"delivery\":{\"id\":\"0123456abcdef\",\"point\":{\"lng\":2.0,\"lat\":"
      "1.0},\"size\":180}}";
  std::cout << jsonString << std::endl;

  rapidjson::Document doc;
  doc.Parse(jsonString);

  auto& deliveryValue = doc["delivery"];
  loggibud::Delivery delivery = loggibud::to_delivery(deliveryValue);

  std::cout << "ID: " << delivery.id << std::endl;
  std::cout << "Point: (" << delivery.point.lng << ", " << delivery.point.lat
            << ")" << std::endl;
  std::cout << "Size: " << delivery.size << std::endl;

  return 0;
}
