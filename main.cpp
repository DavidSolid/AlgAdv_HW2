#include <iostream>
#include "graph_structures/Matrix.h"
#include "utilities/Parser.h"
#include "algorithms/held_karp.h"
#include "algorithms/preorder_2approx.h"
#include "algorithms/cheapest_insertion.h"
#include <filesystem>
#include <chrono>
#include <algorithm>

int main() {
    //IF YOU WANT TO CHECK ONLY ONE GRAPH YOU CAN USE THIS COMMENTED SCRIPT
    /*
    Parser myParser = Parser();
    Graph_Data data = Parser::parse("..\\dataset\\burma14.tsp");

    std::cout << data.dim << std::endl;

    std::cout << data.name << std::endl;

    std::cout << "is geo?: " << (data.ty == coord_type::geo) << std::endl;

    std::cout << "is cartesian?: " << (data.ty == coord_type::cartesian) << std::endl;

    Matrix mat(data.get_weights());

    auto start = std::chrono::steady_clock::now();

    auto cycle_2approx = preorder_2approx(mat);
    auto end_2approx = std::chrono::steady_clock::now();

    auto cycle_cheapest = cheapest_insertion(mat);
    auto end_cheapest = std::chrono::steady_clock::now();

    auto cycle_held_karp = held_karp(mat);
    auto end_held_karp = std::chrono::steady_clock::now();

    std::chrono::duration<double> elapsed_2approx = end_2approx - start;
    std::chrono::duration<double> elapsed_cheapest = end_cheapest - end_2approx;
    std::chrono::duration<double> elapsed_held_karp = end_held_karp - end_cheapest;

    double res_held_karp = 0;
    double res_2approx = 0;
    double res_cheapest = 0;
    for(unsigned int i = 0; i < mat.sizeY(); ++i){
        res_held_karp += mat.at(cycle_held_karp[i], cycle_held_karp[i+1]);
        res_2approx += mat.at(cycle_2approx[i], cycle_2approx[i+1]);
        res_cheapest += mat.at(cycle_cheapest[i], cycle_cheapest[i+1]);
    }

    std::cout << "held_karp : " << res_held_karp << "  time : " << elapsed_2approx.count() << std::endl;
    std::cout << "2approx   : " << res_2approx << "  time : " << elapsed_cheapest.count() << std::endl;
    std::cout << "cheapest  : " << res_cheapest << "  time : " << elapsed_held_karp.count() << std::endl << std::endl;
    */

    //IF YOU WANT TO CHECK ALL THE GRAPH IN THE DATASET YOU CAN USE THIS SCRIPT
    std::string path = "..\\dataset";
    Parser myParser = Parser();
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        Graph_Data data = Parser::parse(entry.path());

        std::cout << data.dim << std::endl;

        std::cout << data.name << std::endl;

        std::cout << "is geo?: " << (data.ty == coord_type::geo) << std::endl;
        std::cout << "is cartesian?: " << (data.ty == coord_type::cartesian) << std::endl;

        Matrix mat(data.get_weights());

        auto start = std::chrono::steady_clock::now();

        auto cycle_2approx = preorder_2approx(mat);
        auto end_2approx = std::chrono::steady_clock::now();

        auto cycle_cheapest = cheapest_insertion(mat);
        auto end_cheapest = std::chrono::steady_clock::now();

        auto cycle_held_karp = held_karp(mat);
        auto end_held_karp = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed_2approx = end_2approx - start;
        std::chrono::duration<double> elapsed_cheapest = end_cheapest - end_2approx;
        std::chrono::duration<double> elapsed_held_karp = end_held_karp - end_cheapest;

        double res_held_karp = 0;
        double res_2approx = 0;
        double res_cheapest = 0;
        for(unsigned int i = 0; i < mat.sizeY(); ++i){
            res_held_karp += mat.at(cycle_held_karp[i], cycle_held_karp[i+1]);
            res_2approx += mat.at(cycle_2approx[i], cycle_2approx[i+1]);
            res_cheapest += mat.at(cycle_cheapest[i], cycle_cheapest[i+1]);
        }

        std::cout << "held_karp : " << res_held_karp << "  time : " << elapsed_2approx.count() << std::endl;
        std::cout << "2approx   : " << res_2approx << "  time : " << elapsed_cheapest.count() << std::endl;
        std::cout << "cheapest  : " << res_cheapest << "  time : " << elapsed_held_karp.count() << std::endl << std::endl;
    }

    return 0;
}