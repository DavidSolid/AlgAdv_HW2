//
// Created by Enrico on 06/05/2020.
//

#ifndef ALGADV_HW2_PREORDER_2APPROX_H
#define ALGADV_HW2_PREORDER_2APPROX_H

#include <vector>
#include "prim.h"

std::vector<unsigned int> preorder(unsigned int f_elem, const Tree_t& tree){
    std::vector<unsigned int> out;

    out.emplace_back(f_elem);
    for(unsigned int i: tree[f_elem]){
        auto part = preorder(i, tree);
        out.insert(out.end(), part.begin(), part.end());
    }
    return out;
}

template <typename T>
std::vector<unsigned int> preorder_2approx(Matrix<T> w){
    Tree_t mst = Prim(w);
    std::vector<unsigned int> chain = preorder(0, mst);
    chain.emplace_back(0);
    return chain;
}

#endif //ALGADV_HW2_PREORDER_2APPROX_H
