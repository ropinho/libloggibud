/**
 * Copyright 2021 <Ronaldd Pinho>
 */
#ifndef LOGGIBUD_JSON_JSON_SCHEMA_H_
#define LOGGIBUD_JSON_JSON_SCHEMA_H_

#include <rapidjson/document.h>
#include <rapidjson/schema.h>

#include <fstream>
#include <stdexcept>
#include <string>

using rapidjson::Document;
using rapidjson::SchemaDocument;
using rapidjson::SchemaValidator;
using std::ifstream;
using std::string;

namespace loggibud::json {
class JSONSchema {
 public:
  explicit JSONSchema(string schema_filepath) {
    ifstream schema_file(schema_filepath);
    if (schema_file.is_open()) {
      auto text = std::string(std::istreambuf_iterator<char>(schema_file),
                              std::istreambuf_iterator<char>());
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

}  // namespace loggibud::json

#endif  // LOGGIBUD_JSON_JSON_SCHEMA_H_
