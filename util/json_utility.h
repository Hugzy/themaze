//
// Created by Magida on 10-11-2018.
//

#include "../include/json11/json11.hpp"

#ifndef THEMAZE_JSON_ROUTINE_H
#define THEMAZE_JSON_ROUTINE_H

json11::Json read_from_file();
const bool write_to_file(const std::string &map, const std::string &file = "");
const bool write_to_file(const json11::Json &map, const std::string &file = "");
const bool append_to_file(const json11::Json &map, const std::string &file = "");
#endif //THEMAZE_JSON_ROUTINE_H
