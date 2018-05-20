#include "MatrixCalc.h"

using namespace std;

template<class T>
MatrixCalc<T>::MatrixCalc(){
    cout << "Enter first matrix" << endl;
    m1 = new Matrix<T>;
    cin >> *m1;
    cout << "Enter second matrix" << endl;
    m2 = new Matrix<T>;
    cin >> *m2;
}

template<class T>
void MatrixCalc<T>::run(){
    while(true)
    {
        cout << "Please choose a function according to the following list: "<< endl << endl;
        cout << "   1. Add" << endl;
        cout << "   2. Subtract" << endl;
        cout << "   3. Multiply" << endl;
        cout << "   4. Transpose" << endl;

        int choice;
        cin >> choice;
        switch(choice)
        {
            case 1:
                add();
                break;
            case 2:
                substract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                transpose();
                break;
            default:
                cout << "Wrong Input" << endl;
        }
    }
}
template<class T>
void MatrixCalc<T>::add(){
    *m1 = *m1 + *m2;
    cout << *m1;
    //m2 = new Matrix<T>;
    //cin >> *m2;
}
template<class T>
void MatrixCalc<T>::substract(){
    *m1 = *m1 - *m2;
    cout << *m1;
    //m2 = new Matrix<T>;
    //cin >> *m2;
}
template<class T>
void MatrixCalc<T>::multiply(){
    *m1 = *m1 * *m2;
    cout << *m1;
    //m2 = new Matrix<T>;
    //cin >> *m2;
}
template<class T>
void MatrixCalc<T>::transpose(){
    m1->transpose();
    m2->transpose();
    cout << *m1 << endl << *m2 << endl;
}
