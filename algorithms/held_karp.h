//
// Created by Alessandro on 12/05/2020.
//

#ifndef ALGADV_HW2_HELD_KARP_H
#define ALGADV_HW2_HELD_KARP_H

#include <vector>
#include <unordered_map>
#include <climits>
#include "../utilities/SubSet.h"
#include "../graph_structures/Matrix.h"
#include <utility>
#include <chrono>

//#define TIMEOUT 2700.00
//#define TIMEOUT 300.00
#define TIMEOUT 27.00

typedef std::pair<unsigned int, std::vector<bool>> key_type;
typedef std::chrono::time_point<std::chrono::steady_clock> race_time;

template <typename T>
T held_karp_visit(const unsigned int v, SubSet S, const Matrix<T> w, std::unordered_map<key_type, T, std::function<size_t(key_type)>>& D,std::unordered_map<key_type, unsigned int, std::function<size_t(key_type)>>& Pi, race_time& starting_time, bool expired){
    if (S.only_vertex(v)){
        return w.at(v,0);
    }else if(D.contains(std::make_pair(v, S.collection))){
        return D.at(std::make_pair(v, S.collection));
    }else {
        T mindist = (T) INT_MAX;
        int minprec = -1;
        S.remove(v);
        //u = 1 because we know that 0 was already removed from S as 0 is the starting node
        for (int u = 1; expired && ( u < w.sizeY() ); ++u) {
            if (S.at(u)) {
                T dist = held_karp_visit(u, S, w, D, Pi, starting_time, expired);
                if ((dist + w.at(u, v)) < mindist) {
                    mindist = dist + w.at(u, v);
                    minprec = u;
                }
                std::chrono::duration<double> now = std::chrono::steady_clock::now() - starting_time;
                if(now.count() >= TIMEOUT)
                    expired = false;
            }
        }
        S.add(v);
        D.insert_or_assign(std::make_pair(v, S.collection), mindist);
        Pi.insert_or_assign(std::make_pair(v, S.collection), minprec);
        return mindist;
    }
}


template <typename T>
std::vector<unsigned int> held_karp(Matrix<T> w) {
    SubSet S(w.sizeX(), true);

    auto hash = [](key_type a){
        return std::hash<unsigned int>()(a.first) ^ std::hash<std::vector<bool>>()(a.second);
    };

    std::unordered_map<key_type, T, std::function<size_t(key_type)>> D(1, hash);

    std::unordered_map<key_type, unsigned int, std::function<size_t(key_type)>> Pi(1, hash);

    race_time starting_time = std::chrono::steady_clock::now();

    T value = held_karp_visit(0, S, w, D, Pi, starting_time, true);

    std::vector<unsigned int> C(1,0);

    SubSet Y(w.sizeY(), true);

    for(int i = 0; Pi.contains(std::make_pair(C[i], Y.collection)); ++i){
        C.push_back(Pi.at(std::make_pair(C[i], Y.collection)));
        Y.remove(C[i]);
    }
    C.push_back(0);

    return C;
}

#endif //ALGADV_HW2_HELD_KARP_H
