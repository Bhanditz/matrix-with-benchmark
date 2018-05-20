#include <iostream>
#include "MatrixCalc.cpp"
#include <algorithm>
#include <time.h>
using namespace std;
template <class T>
double runOnce(MatrixCalc<T> MC)
{
    clock_t  t =clock();
    MC.add();
    MC.substract();
    MC.multiply();
    MC.transpose();
    t= clock() -t;
    return  (double) (t) /CLOCKS_PER_SEC;
}
int main()
{
    try
    {
        MatrixCalc<float> mc;
        MatrixCalc<double> mc1;
        double intTime=runOnce(mc);
        double doubleTime=runOnce(mc1);
        cout<<"float time "<< intTime<<endl;
        cout<<"double time "<< doubleTime<<endl;
    }
        catch (...)
        { cout << "Error has occurred. "; }
}
