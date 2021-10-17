#ifndef LOGGIBUD_JSON_JSONSCHEMA_H_
#define LOGGIBUD_JSON_JSONSCHEMA_H_

#include <fstream>
#include <string>
#include <stdexcept>
#include <rapidjson/document.h>
#include <rapidjson/schema.h>

using std::string;
using std::ifstream;
using rapidjson::Document;
using rapidjson::SchemaDocument;
using rapidjson::SchemaValidator;

namespace loggibud::json
{
    class JSONSchema {
    public:
        JSONSchema(string schema_filepath) {
            ifstream schema_file(schema_filepath);
            if (schema_file.is_open()) {
                auto text = std::string(
                    std::istreambuf_iterator<char>(schema_file),
                    std::istreambuf_iterator<char>()
                );
                this->document.Parse(text.c_str());
                schema_file.close();
            } else {
                throw std::runtime_error("Impossible open JSON Schema file");
            }
        }

        bool validate(const Document &document) {
            SchemaDocument schema(this->document);
            SchemaValidator validator(schema);
            return document.Accept(validator);
        }

    protected:
        Document document;
    };

    /**
     * @class CVRPInstanceSchema
     * 
     * Classe que armazena as definições de schema JSON para as instâncias de
     * problemas de roteamentod e veículos com restrição de capacidade 
     */
    class CVRPIstanceSchema : public JSONSchema {
    public:
        CVRPIstanceSchema() : JSONSchema("../../cvrp_instance.schema.json") {}
    };

}

#endif