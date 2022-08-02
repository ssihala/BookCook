//
// Created by sihala on 8/1/22.
//

#pragma once
#include <fstream>
#include "hashtable.h"
#include "Graph.h"
#include "../nlohmann/json.hpp"

void loadHash(Hashtable& hash, std::unordered_map<int, std::string>& idMapping);
void loadGraph(Graph& graph);