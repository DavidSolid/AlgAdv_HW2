#include <iostream>
#include "graph_structures/Matrix.h"
#include "utilities/Parser.h"
#include <filesystem>
#define SIZEX 10
#define SIZEY 200

int main() {
    //test matrix
    Matrix<double> a(SIZEX, SIZEY);
    a.update(22,0, 69);
    for(int i=0; i< SIZEX; ++i){
        for(int j=0; j<SIZEY; ++j){
            std::cout << a.at(i,j) << " ";
        }
        std::cout << std::endl;
    }

    //test parser
    /*Parsed_Map data = Parser::parse("..\\dataset\\ulysses22.tsp");
    std::cout << data.dim << std::endl;
    std::cout << data.name << std::endl;
    for(auto it: data.cities)
        std::cout << it.first << "," << it.second << std::endl;*/
    return 0;
}