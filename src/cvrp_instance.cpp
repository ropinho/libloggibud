#include "../include/loggibud/cvrp_instance.h"

loggibud::CVRPInstance loggibud::CVRPInstance::from_file(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        auto filecontent = string(
            std::istreambuf_iterator<char>(file),
            std::istreambuf_iterator<char>()
        );
        file.close();

        CVRPInstance instance;
        rapidjson::Document d;
        loggibud::json::JSONSchema schema("schemas/cvrp_instance.schema.json");
        // const char *LOGGIBUD_SCHEMAS_DIR = std::getenv("LOGGIBUD_SCHEMAS_DIR");

        d.Parse(filecontent.c_str());
        if (!schema.validate(d)) {
            throw std::logic_error("JSON file is not in accordance with CVRPInstance schema.");
        }

        instance.name = d["name"].GetString();
        instance.region = d["region"].GetString();

        // TODO: Finalize CVRPInstance JSON parsing.
        return instance;
    } else {
        throw std::runtime_error("Impossible open the file");
    }
}
