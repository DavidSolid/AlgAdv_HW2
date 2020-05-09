#include <utility>

//
// Created by Enrico on 06/05/2020.
//

#ifndef ALGADV_HW2_GRAPH_DATA_H
#define ALGADV_HW2_GRAPH_DATA_H
#define RADIUS 6372.795477598
#define PI 3.141592

#include <functional>
#include <cmath>

//coordinate types enum
enum class coord_type{
    cartesian,
    geo,
    none
};

//parsed data type
template <typename T>
class Graph_Data{
    typedef std::vector<std::pair<T, T>> Coordinate_List;
public:
    std::string name;
    coord_type ty;
    unsigned int dim;
    Coordinate_List cities;

    Graph_Data(std::string , coord_type, unsigned int, Coordinate_List );
    [[nodiscard]] Matrix<T> get_weights() const;

private:
    static T to_radians(const T&);
};

template <typename T>
Graph_Data<T>::Graph_Data(std::string  n, coord_type tp, unsigned int d, Graph_Data::Coordinate_List  cs): name(std::move(n)), ty(tp), dim(d), cities(std::move(cs)) {}

template <typename T>
Matrix<T> Graph_Data<T>::get_weights() const {
    std::function<T(std::pair<T, T>, std::pair<T, T>)> distance_fun;
    if(ty == coord_type::cartesian){
        distance_fun = [](std::pair<T, T> p, std::pair<T, T> q){
            return round(sqrt(pow(p.first - q.first, 2) + pow(p.second - q.second, 2)));
        };
    }
    else{
        distance_fun = [](std::pair<T, T> p, std::pair<T, T> q){
            p = std::make_pair(to_radians(p.first), to_radians(p.second));
            q = std::make_pair(to_radians(q.first), to_radians(q.second));
            return trunc(RADIUS * acos(sin(p.first) * sin(q.first) + cos(p.first) * cos(q.first) * cos(p.second-q.second)));
        };
    }

    Matrix<T> w(dim, dim);
    for(unsigned int i = 0; i < dim; ++i){
        for(unsigned int j = 0; j < dim; ++j){
            double weight = distance_fun(cities[i], cities[j]);
            if(i == j){
                w.update(i, j, 0);
            } else w.update(i, j, weight);
        }
    }
    return w;
}

template<typename T>
T Graph_Data<T>::to_radians(const T& x) {
    T deg = trunc(x);
    T min = x - deg;
    return PI*(deg + 5 * min / 3)/180;
}

#endif //ALGADV_HW2_GRAPH_DATA_H
