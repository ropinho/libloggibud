#include <iostream>
#include <string>
#include <loggibud/cvrp_instance.h>

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cerr << "Use " << argv[1] << " [path/to/instance.json]\n";
        return EXIT_FAILURE;
    }

    std::string filename(argv[1]);

    try {
        loggibud::CVRPInstance problem = loggibud::CVRPInstance::from_file(filename); 
        std::cout << "Name: " << problem.name << std::endl;
        std::cout << "Num. of deliveries: " << problem.deliveries.size() << std::endl;
    } catch(std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
