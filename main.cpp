#include <iostream>
#include "graph_structures/Matrix.h"
#include "utilities/Parser.h"
#include "algorithms/preorder_2approx.h"
#include <filesystem>
#include <bitset>
#include <algorithm>
#include <cmath>
#define SIZEX 10
#define SIZEY 200

int main() {
    //test bitset
    /*unsigned int n_elems = 3;
    std::bitset<5> bset((unsigned long long)pow(2,n_elems) - 1);
    std:: string bset_string = bset.to_string();
    std::cout << bset_string << std::endl;
    while(std::next_permutation(bset_string.begin(), bset_string.end())){
        std::bitset<5> i(bset_string);
        std::cout << i << std::endl;
    }*/

    //test matrix
    /*Matrix<double> a(SIZEX, SIZEY);
    a.update(22,0, 69);
    for(int i=0; i< SIZEX; ++i){
        for(int j=0; j<SIZEY; ++j){
            std::cout << a.at(i,j) << " ";
        }
        std::cout << std::endl;
    }*/

    //test parser
    /*Graph_Data data = Parser::parse("..\\dataset\\ulysses22.tsp");
    std::cout << data.dim << std::endl;
    std::cout << data.name << std::endl;
    std::cout << "is geo?: " << (data.ty == coord_type ::geo) << std::endl;
    Matrix w(data.get_weights());
    for(unsigned int i=0; i < data.dim; ++i){
        for(unsigned int j=0; j < data.dim; ++j){
            std::cout << w.at(i, j) << " ";
        }
        std::cout << std::endl;
    }*/

    //test preorder_2approx
    Graph_Data data = Parser::parse("..\\dataset\\eil51.tsp");
    std::cout << data.dim << std::endl;
    std::cout << data.name << std::endl;
    /*for(auto i: data.cities){
        std::cout << i.first << "-" << i.second << std::endl;
    }*/
    std::cout << "is geo?: " << (data.ty == coord_type ::geo) << std::endl;
    std::cout << "is cartesian?: " << (data.ty == coord_type ::cartesian) << std::endl;
    Matrix mat(data.get_weights());
    /*for(unsigned int i=0; i < data.dim; ++i){
        for(unsigned int j=0; j < data.dim; ++j){
            std::cout << mat.at(i, j) << " ";
        }
        std::cout << std::endl;
    }*/

    auto cycle = preorder_2approx(mat);
    double res = 0;
    for(unsigned int i = 0; i < cycle.size() - 1; ++i){
        res += mat.at(cycle[i], cycle[i+1]);
    }
    std::cout << res << std::endl;
    return 0;
}