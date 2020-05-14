#include <iostream>
#include "graph_structures/Matrix.h"
#include "utilities/Parser.h"
#include "algorithms/held_karp.h"
#include "algorithms/preorder_2approx.h"
#include "algorithms/cheapest_insertion.h"
#include <filesystem>
#include <bitset>
#include <algorithm>
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

    std::string path = "..\\dataset";
    Parser myParser = Parser();
    //for (const auto &entry : std::filesystem::directory_iterator(path)) {
        //Graph_Data data = Parser::parse(entry.path());
        Graph_Data data = Parser::parse("..\\dataset\\burma14.tsp");
        std::cout << data.dim << std::endl;
        std::cout << data.name << std::endl;

        std::cout << "is geo?: " << (data.ty == coord_type::geo) << std::endl;
        std::cout << "is cartesian?: " << (data.ty == coord_type::cartesian) << std::endl;
        Matrix mat(data.get_weights());


        //auto cycle_2approx = preorder_2approx(mat);
        //auto cycle_cheapest = cheapest_insertion(mat);
        auto keld_harp = held_karp(mat);
        /*
        double res_2approx = 0;
        double res_cheapest = 0;
        for(unsigned int i = 0; i < cycle_2approx.size() - 1; ++i){
            res_2approx += mat.at(cycle_2approx[i], cycle_2approx[i+1]);
            res_cheapest += mat.at(cycle_cheapest[i], cycle_cheapest[i+1]);
        }
        std::cout << "2approx  : " << res_2approx << std::endl;
        std::cout << "cheapest : " << res_cheapest << std::endl << std::endl;
         */
        std::cout << "schifo  : " << keld_harp << std::endl << std::endl;
   //}

    return 0;
}