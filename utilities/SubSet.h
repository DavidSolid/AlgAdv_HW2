//
// Created by Alessandro on 14/05/2020.
//

#ifndef ALGADV_HW2_SUBSET_H
#define ALGADV_HW2_SUBSET_H

#include <vector>

class SubSet {
public:
    std::vector<bool> collection;
    unsigned int present;
    SubSet(unsigned int);
    SubSet(unsigned int, bool);
    [[nodiscard]] bool only_vertex(unsigned int) const;
    [[nodiscard]] bool at(unsigned int) const;
    void remove(unsigned int);
    void add(unsigned int);
};

SubSet::SubSet(unsigned int size): collection(size, false), present(0){};

SubSet::SubSet(unsigned int size, bool start): collection(size, start), present(size){
    if(!start){
        present = 0;
    }
}

bool SubSet::only_vertex(unsigned int v) const {
    return ((present == 1) && collection[v]);
}

bool SubSet::at(unsigned int v) const {
    return collection[v];
}

void SubSet::remove(unsigned int v) {
    if(collection[v]){
        collection[v] == false;
        --present;
    }
}

void SubSet::add(unsigned int v) {
    if(!collection[v]){
        collection[v] == true;
        ++present;
    }
}

#endif //ALGADV_HW2_SUBSET_H
