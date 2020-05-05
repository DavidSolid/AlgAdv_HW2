#include <iostream>
#include "graph_structures/AdjacencyMatrix.h"
#include "utilities/Parser.h"
#include <filesystem>
#define SIZE 10

int main() {
    Parsed_Map data = Parser::parse("..\\dataset\\ulysses22.tsp");
    std::cout << data.dim << std::endl;
    std::cout << data.name << std::endl;
    for(auto it: data.cities)
        std::cout << it.first << "," << it.second << std::endl;
    return 0;
}