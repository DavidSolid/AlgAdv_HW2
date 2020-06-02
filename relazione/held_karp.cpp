typedef std::pair<unsigned int, std::vector<bool>> key_type;
typedef std::unordered_map<key_type, T, std::function<size_t(key_type)>> D_Map
typedef std::unordered_map<key_type, unsigned int, std::function<size_t(key_type)>> Pi_Map
typedef std::chrono::time_point<std::chrono::steady_clock> race_time;
T held_karp_visit(int v, SubSet S, Matrix<T> w, D_Map D, Pi_Map Pi, race_time starting_time, bool expired){
    if (S.only_vertex(v)){
        return w.at(v,0);
    }else if(D.contains(std::make_pair(v, S.collection))){
        return D.at(std::make_pair(v, S.collection));
    }else {
        T mindist = (T) INT_MAX;
        int minprec = -1;
        S.remove(v);
        for (int u = 1; expired && ( u < w.sizeY() ); ++u) {
            if (S.at(u)) {
                T dist = held_karp_visit(u, S, w, D, Pi, starting_time, expired);
                if ((dist + w.at(u, v)) < mindist) {
                    mindist = dist + w.at(u, v);
                    minprec = u;
                }
                std::chrono::duration<double> now = std::chrono::steady_clock::now()-starting_time;
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