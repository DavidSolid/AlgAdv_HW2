//
// Created by Alessandro on 12/05/2020.
//

#ifndef ALGADV_HW2_HELD_KARP_H
#define ALGADV_HW2_HELD_KARP_H

#include <vector>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
//#include "graph_structures/Matrix.h"

template <typename T>
T held_karp_visit(const unsigned int v, const std::vector<bool> S, const Matrix<T> w){
    if (S.test(v) && S.count() == 1){
        return w.at(v,0);
    }
    // tanto non capita
    // else if (D[]){}
    else {
        T mindist = (T)INT_MAX;
        int minprec = -1;
        S.set(v, 0);
        for (auto u:S){
            if(S.test(u)){
                T dist = held_karp_visit(u,S,w);
                if ((dist + w.at(u,v)) < mindist) {
                    mindist = dist + w.at(u,v);
                    minprec = u;
                }
            }
        }
        return mindist;
    }
}


template <typename T>
T held_karp(Matrix<T> w) {
    //dichiaro D
    //dichiaro pi
    //Matrix<T> D(w.sizeX(),w.sizeY());
    //Matrix<unsigned int> pi(w.sizeX(),w.sizeY());

    std::vector<bool> S(w.sizeX(),true);

    return held_karp_visit(0,S,w);
}

#endif //ALGADV_HW2_HELD_KARP_H
