//
// Created by Enrico on 06/05/2020.
//

#ifndef ALGADV_HW2_PRIM_H
#define ALGADV_HW2_PRIM_H

#include <numeric>
#include "../graph_structures/Matrix.h"
#include "../data_structures/MinHeap.h"
#include <climits>
typedef std::vector<std::vector<unsigned int>> Tree_t;

template <typename T>
Tree_t Prim(const Matrix<T>&);

template <typename T>
Tree_t Prim(const Matrix<T>& G){
    //s == 0
    unsigned int n_vec = G.sizeX();

    //initialize Key[]
    std::vector<std::pair<T, int>> V(n_vec);

    //initialize pi[]
    std::vector<int> pi(n_vec);

    //line 1 : for each u in  V do
    for(unsigned int i = 1; i < n_vec; ++i){

        //line 2 : Key[u] = +INF
        V[i] = std::make_pair((T)INT_MAX, i);

        //line 3 : pi[u] <- NULL
        pi[i] = -1;
    }

    //line 4 : Key[s] <- 0
    V[0] = std::make_pair(0, 0);
    pi[0] = -1;

    //line 5 : Q <- V
    MinHeap<T> Q(V);

    //line 6 : while Q is not empty do
    while(Q.size()!=0){

        //line 7 : u <- extractMin(Q)
        std::pair<T, int> u = Q.extractMin();

        //line 8 : for each v adjacent to u do (all)
        for(unsigned int j = 0; j < G.sizeY(); ++j){
            std::pair<int, T> v = std::make_pair(j, G.at(u.second, j));

            //line 9 : if v in Q and w(u,v) < Key[v] then
            if(Q.exists(v.first) && v.second < V[v.first].first){
                Q.decreaseUpdate(v.second, v.first);

                //line 10 : pi[v] <- u
                pi[v.first] = u.second;

                //line 11 : Key[v] <- w(u,v)
                V[v.first].first = v.second;
            }
        }
    }

    Tree_t tree(n_vec);
    for(unsigned int i = 0; i < n_vec; ++i){
        if(pi[i] != -1){
            tree[pi[i]].emplace_back(i);
        }
    }
    return tree;
}

#endif //ALGADV_HW2_PRIM_H
