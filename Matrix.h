#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<class T>
class Matrix{
    private:
        vector<vector <T> > mtrx;
    public:
        Matrix();
        Matrix(int, int);
        Matrix(const Matrix<T>&);
        ~Matrix();
        Matrix operator+(const Matrix<T>&);
        Matrix operator-(const Matrix<T>&);
        Matrix operator*(const Matrix<T>&);
        void transpose();
        template<class Temp>
        friend ostream& operator<<(ostream& out, const Matrix<Temp>&);
        template<class Temp>
        friend istream& operator>>(istream& in, Matrix<Temp>&);
};
#endif // MATRIX_H
