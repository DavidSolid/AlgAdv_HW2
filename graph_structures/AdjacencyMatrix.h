//
// Created by Enrico on 05/05/2020.
//

#ifndef ALGADV_HW2_ADJACENCYMATRIX_H
#define ALGADV_HW2_ADJACENCYMATRIX_H

template <typename T>
class AdjacencyMatrix{
    //friend AdjacencyMatrix::AdjacencyMatrix(AdjacencyMatrix&&) noexcept;
private:
    T* matrix;
    unsigned int sz;
public:
    explicit AdjacencyMatrix(unsigned int);
    AdjacencyMatrix(const AdjacencyMatrix&);
    AdjacencyMatrix(AdjacencyMatrix&&) noexcept;
    ~AdjacencyMatrix();

    T*& mat();//TODO: modify and add friend declaration
    [[nodiscard]] unsigned int size() const;
    void update(unsigned int, unsigned int, const T&);
    [[nodiscard]] T at(unsigned int, unsigned int) const;
};

template <typename T>
AdjacencyMatrix<T>::AdjacencyMatrix(unsigned int s): matrix(new T[s*s]), sz(s){
    for(unsigned int i = 0; i < s*s; ++i){
        matrix[i] = -1;
    }
}

template <typename T>
AdjacencyMatrix<T>::AdjacencyMatrix(const AdjacencyMatrix& cpy): matrix(new T[cpy.size()*cpy.size()]), sz(cpy.size()){
    for(unsigned int i = 0; i < cpy.size(); ++i){
        for(unsigned int j = 0; j < cpy.size(); ++j)
            update(i, j, cpy.at(i, j));
    }
}

template <typename T>
AdjacencyMatrix<T>::AdjacencyMatrix(AdjacencyMatrix&& cpy) noexcept: matrix(cpy.mat()), sz(cpy.size()){
    cpy.mat() = nullptr;
}

template <typename T>
AdjacencyMatrix<T>::~AdjacencyMatrix() {
    delete[] matrix;
}

template<typename T>
T*& AdjacencyMatrix<T>::mat() {
    return matrix;
}

template <typename T>
unsigned int AdjacencyMatrix<T>::size() const{
    return sz;
}

template<typename T>
void AdjacencyMatrix<T>::update(unsigned int x, unsigned int y, const T& val) {
    matrix[size()*y + x] = val;
}

template <typename T>
T AdjacencyMatrix<T>::at(unsigned int x, unsigned int y) const{
    return matrix[size()*y + x];
}

#endif //ALGADV_HW2_ADJACENCYMATRIX_H
