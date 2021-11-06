/**
 * Copyright 2021 <Ronaldd Pinho>
 */
#include <loggibud/cvrp_instance.h>

#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    std::cerr << "Use " << argv[0] << " [path/to/instance.json]" << std::endl;
    return EXIT_FAILURE;
  }

  std::string filename(argv[1]);

  loggibud::CVRPInstance problem = loggibud::CVRPInstance::from_file(filename);
  std::cout << "Name: " << problem.name << std::endl;
  std::cout << "Region: " << problem.region << std::endl;

  std::cout << "Origin: (lat=" << problem.origin.lat
            << ", lng=" << problem.origin.lng << ")" << std::endl;

  std::cout << "Num. of deliveries: " << problem.deliveries.size() << std::endl;

  return EXIT_SUCCESS;
}
