//
// Created by Alessandro on 12/05/2020.
//

#ifndef ALGADV_HW2_HELD_KARP_H
#define ALGADV_HW2_HELD_KARP_H

#include <vector>
#include <unordered_map>
#include <bitset>
#include <numeric>
#include <climits>
#include <iostream>
#include "../utilities/SubSet.h"
#include "../graph_structures/Matrix.h"

template <typename T>
T held_karp_visit(const unsigned int v, SubSet S, const Matrix<T> w){
    if (S.only_vertex(v)){
        return w.at(v,0);
    }
    // tanto non capita
    // else if (D[]){}
    else {
        T mindist = (T)INT_MAX;
        int minprec = -1;
        S.remove(v);
        //i = 1 because we know that 0 was already removed from S
        for (int u = 1; u < w.sizeY(); ++u){
            if(S.at(u)){
                T dist = held_karp_visit(u,S,w);
                if ((dist + w.at(u,v)) < mindist) {
                    mindist = dist + w.at(u,v);
                    minprec = u;
                }
            }
        }
        std::cout << mindist << std::endl;
        return mindist;
    }
}


template <typename T>
T held_karp(Matrix<T> w) {
    //dichiaro D
    //dichiaro pi
    //Matrix<T> D(w.sizeX(),w.sizeY());
    //Matrix<unsigned int> pi(w.sizeX(),w.sizeY());

    SubSet S(w.sizeX(), true);

    //std::vector<bool> S(w.sizeX(),true);

    std::unordered_map<std::pair<unsigned int, std::vector<bool>>, int> D(0);

    return held_karp_visit(0,S,w);
}

#endif //ALGADV_HW2_HELD_KARP_H
