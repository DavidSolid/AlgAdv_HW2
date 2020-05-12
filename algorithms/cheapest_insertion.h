//
// Created by Alessandro on 08/05/2020.
//

#ifndef ALGADV_HW2_CHEAPEST_INSERTION_H
#define ALGADV_HW2_CHEAPEST_INSERTION_H

#include <vector>
#include <climits>

template <typename T>
std::vector<unsigned int> cheapest_insertion(Matrix<T> w){
    //initialize the partial circuit with only 0
    std::vector<unsigned int> C(2,0);

    //find j who minimize w(0,j)
    T find_min = (T)INT_MAX;
    unsigned int find_value = -1;
    for(unsigned int j = 1; j<w.sizeY(); ++j){
        if(w.at(0,j) < find_min) {
            find_min = w.at(0, j);
            find_value = j;
        }
    }
    //add j to C -> C(0,j,0)
    C.insert(C.begin() + 1, find_value);
    bool L[w.sizeY()] = {0};
    L[0], L[find_value] = true, true;

    //select k
    while(C.size() <= w.sizeY()){
        find_min = (T)INT_MAX;
        find_value = -1;
        unsigned int temp_pos = INT_MAX;
        //we always know that 0 is already inside C
        for(unsigned int k = 1; k<w.sizeY(); ++k){
            //check if j is already inside C
            if(!L[k]){
                //C.size()-1 because C is a circuit so C[0] == C[end]
                for(unsigned int i = 0; i<C.size()-1; ++i) {
                    if((w.at(C[i],k) + w.at(C[i+1],k) - w.at(C[i],C[i+1])) < find_min){
                        find_min = w.at(i,k) + w.at(C[i],k) - w.at(i,C[i]);
                        find_value = k;
                        temp_pos = i+1;
                    }
                }
            }
        }
        C.insert(C.begin() + temp_pos, find_value);
        L[find_value] = true;
    }
    return C;
}

#endif //ALGADV_HW2_CHEAPEST_INSERTION_H
