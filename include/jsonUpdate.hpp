#ifndef JSONUPDATE_H
#define JSONUPDATE_H

#include "json.hpp"
using json = nlohmann::ordered_json;

void updateJson(std::string arquivo_path, json novo_dado);

#endif