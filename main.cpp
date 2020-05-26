#include <iostream>
#include "graph_structures/Matrix.h"
#include "utilities/Parser.h"
#include "algorithms/held_karp.h"
#include "algorithms/preorder_2approx.h"
#include "algorithms/cheapest_insertion.h"
#include <filesystem>
#include <chrono>
#include <algorithm>
#define SIZEX 10
#define SIZEY 200


int main() {
    std::string path = "..\\dataset";
    Parser myParser = Parser();
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        Graph_Data data = Parser::parse(entry.path());
        //Graph_Data data = Parser::parse("..\\dataset\\burma14.tsp");

        std::cout << data.dim << std::endl;
        std::cout << data.name << std::endl;

        std::cout << "is geo?: " << (data.ty == coord_type::geo) << std::endl;
        std::cout << "is cartesian?: " << (data.ty == coord_type::cartesian) << std::endl;

        Matrix mat(data.get_weights());

        auto cycle_2approx = preorder_2approx(mat);

        auto cycle_cheapest = cheapest_insertion(mat);

        auto cycle_held_karp = held_karp(mat);

        double res_held_karp = 0;
        double res_2approx = 0;
        double res_cheapest = 0;
        for(unsigned int i = 0; i < mat.sizeY(); ++i){
            res_held_karp += mat.at(cycle_held_karp[i], cycle_held_karp[i+1]);
            res_2approx += mat.at(cycle_2approx[i], cycle_2approx[i+1]);
            res_cheapest += mat.at(cycle_cheapest[i], cycle_cheapest[i+1]);
        }

        std::cout << "held_karp : " << res_held_karp << std::endl;
        std::cout << "2approx   : " << res_2approx << std::endl;
        std::cout << "cheapest  : " << res_cheapest << std::endl << std::endl;
    }

    return 0;
}