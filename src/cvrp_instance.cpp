#include "../include/loggibud/cvrp_instance.h"

loggibud::CVRPInstance loggibud::CVRPInstance::from_file(std::string filename) {
    const std::string kLoggibudSchemasDir = std::getenv("LOGGIBUD_SCHEMAS_DIR")
        ? std::string(std::getenv("LOGGIBUD_SCHEMAS_DIR"))
        : throw std::runtime_error("Var LOGGIBUD_SCHEMAS_DIR not found");

    std::ifstream file(filename);
    if (kLoggibudSchemasDir.empty()) {
        throw std::runtime_error("LOGGIBUD_SCHEMAS_DIR var is not set.");
    }

    if (file.is_open()) {
        auto filecontent = string(
            std::istreambuf_iterator<char>(file),
            std::istreambuf_iterator<char>()
        );
        file.close();

        std::string schema_path = kLoggibudSchemasDir + "/cvrp_instance.schema.json";
        
        CVRPInstance instance;
        rapidjson::Document d;
        loggibud::json::JSONSchema schema(schema_path);

        d.Parse(filecontent.c_str());
        if (!schema.validate(d)) {
            throw std::logic_error("JSON file is not in accordance with CVRPInstance schema.");
        }

        instance.name = std::string(d["name"].GetString());
        instance.region = std::string(d["region"].GetString());
        instance.vehicle_capacity = (size_t) d["vehicle_capacity"].GetInt64();
        instance.origin = loggibud::json::read_point(d["origin"]);
        
        auto a = d["deliveries"].GetArray();
        for (auto elem = a.Begin(); elem != a.End(); elem++) {
            instance.deliveries.push_back(loggibud::json::read_delivery(*elem));
        }
        return instance;
    } else {
        throw std::runtime_error("Impossible open the file");
    }
}
