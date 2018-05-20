#ifndef MATRIXCALC_H
#define MATRIXCALC_H
#include <iostream>
#include "Matrix.cpp"

using namespace std;

template<class T>
class MatrixCalc{
    private:
        Matrix<T> *m1, *m2;
    public:
    MatrixCalc();
    void run();
    void add();
    void substract();
    void multiply();
    void transpose();
};
#endif // MATRIXCALC_H
