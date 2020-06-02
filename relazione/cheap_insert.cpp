std::vector<unsigned int> cheapest_insertion(Matrix<T> w){
    std::vector<unsigned int> C(2,0);
    T find_min = (T)INT_MAX;
    int find_node = -1;
    for(int j = 1; j<w.sizeY(); ++j){
        if(w.at(0,j) < find_min) {
            find_min = w.at(0, j);
            find_node = j;
        }
    }
    C.insert(C.begin() + 1, find_node);
    SubSet L(w.sizeY());
    L.add(0); L.add(find_node);
    while(C.size() <= w.sizeY()){
        find_min = (T)INT_MAX;
        find_node = -1;
        unsigned int temp_pos = INT_MAX;
        for(int k = 1; k<w.sizeY(); ++k){
            if(!L.at(k)){
                for(unsigned int i = 0; i<C.size()-1; ++i) {
                    if((w.at(C[i],k) + w.at(C[i+1],k) - w.at(C[i],C[i+1])) < find_min){
                        find_min = w.at(C[i],k) + w.at(C[i+1],k) - w.at(C[i],C[i+1]);
                        find_node = k;
                        temp_pos = i+1;
                    }
                }
            }
        }
        C.insert(C.begin() + temp_pos, find_node);
        L.add(find_node);
    }
    return C;
}
