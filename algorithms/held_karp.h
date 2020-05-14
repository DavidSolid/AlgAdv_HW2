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
#include <utility>
typedef std::pair<unsigned int, std::vector<bool>> key_type;

template <typename T>
T held_karp_visit(const unsigned int v, SubSet S, const Matrix<T> w, std::unordered_map<key_type, T, std::function<size_t(key_type)>>& D){
    if (S.only_vertex(v)){
        return w.at(v,0);
    }
    try {
        return D.at(std::make_pair(v, S.collection));
    }
    catch (...) {}
    T mindist = (T)INT_MAX;
    int minprec = -1;
    S.remove(v);
    //i = 1 because we know that 0 was already removed from S
    for (unsigned int u = 1; u < w.sizeY(); ++u){
        if(S.at(u)){
            T dist = held_karp_visit(u,S,w,D);
            if ((dist + w.at(u,v)) < mindist) {
                mindist = dist + w.at(u,v);
                minprec = u;
            }
        }
    }
    //std::cout << mindist << std::endl;
    D[std::make_pair(minprec, S.collection)] = mindist;
    return mindist;
}


template <typename T>
T held_karp(Matrix<T> w) {
    //dichiaro D
    //dichiaro pi
    //Matrix<T> D(w.sizeX(),w.sizeY());
    //Matrix<unsigned int> pi(w.sizeX(),w.sizeY());

    SubSet S(w.sizeX(), true);

    //std::vector<bool> S(w.sizeX(),true);
    auto hash = [](key_type a){
        return std::hash<unsigned int>()(a.first) ^ std::hash<std::vector<bool>>()(a.second);
    };
    std::unordered_map<key_type, T, std::function<size_t(key_type)>> D(1, hash);

    return held_karp_visit(0,S,w,D);
}

#endif //ALGADV_HW2_HELD_KARP_H
