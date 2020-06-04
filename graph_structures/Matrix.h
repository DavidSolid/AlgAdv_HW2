//
// Created by Enrico on 05/05/2020.
//

#ifndef ALGADV_HW2_MATRIX_H
#define ALGADV_HW2_MATRIX_H

template <typename T>
class Matrix{
    //friend Matrix::Matrix(Matrix&&) noexcept;
private:
    T* matrix;
    unsigned int sx;
    unsigned int sy;
public:
    explicit Matrix(unsigned int, unsigned int);
    Matrix(const Matrix&);
    Matrix(Matrix&&) noexcept;
    ~Matrix();

    T*& mat();
    [[nodiscard]] unsigned int sizeX() const;
    [[nodiscard]] unsigned int sizeY() const;
    void update(unsigned int, unsigned int, const T&);
    [[nodiscard]] T at(unsigned int, unsigned int) const;
};

template <typename T>
Matrix<T>::Matrix(unsigned int x, unsigned int y): matrix(new T[x * y]), sx(x), sy(y){
    for(unsigned int i = 0; i < x*y; ++i){
        matrix[i] = -1;
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& cpy): matrix(new T[cpy.sizeX() * cpy.sizeY()]), sx(cpy.sizeX()), sy(cpy.sizeY()){
    for(unsigned int i = 0; i < cpy.sizeX(); ++i){
        for(unsigned int j = 0; j < cpy.sizeY(); ++j)
            update(i, j, cpy.at(i, j));
    }
}

template <typename T>
Matrix<T>::Matrix(Matrix&& cpy) noexcept: matrix(cpy.mat()), sx(cpy.sizeX()), sy(cpy.sizeY()){
    cpy.mat() = nullptr;
}

template <typename T>
Matrix<T>::~Matrix(){
    delete[] matrix;
}

template<typename T>
T*& Matrix<T>::mat() {
    return matrix;
}

template <typename T>
unsigned int Matrix<T>::sizeX() const{
    return sx;
}

template <typename T>
unsigned int Matrix<T>::sizeY() const{
    return sy;
}

template<typename T>
void Matrix<T>::update(unsigned int x, unsigned int y, const T& val) {
    matrix[sizeY()*x + y] = val;
}

template <typename T>
T Matrix<T>::at(unsigned int x, unsigned int y) const{
    return matrix[sizeY()*x + y];
}

#endif //ALGADV_HW2_MATRIX_H
