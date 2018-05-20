#include "Matrix.h"
#include <bits/stdc++.h>
using namespace std;

template<class T>
Matrix<T>::Matrix() {}

template<class T>
Matrix<T>::Matrix(int rowSize, int columnSize)
{
    for(int i = 0; i < rowSize; i++)
    {
        vector<T> col;
        col.resize(columnSize);
        for(int j = 0; j < columnSize; j++)
        {
            cin >> col[j];
        }
        mtrx.push_back(col);
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& obj)
{
    int rowSize = obj.mtrx.size();
    int colSize = obj.mtrx[0].size();
    for(int i = 0; i < rowSize; i++)
    {
        vector<T> col;
        col.resize(colSize);
        for(int j = 0; j < colSize; j++)
        {
            col[j] = obj.mtrx[i][j];
        }
        mtrx.push_back(col);
    }
}

template<class T>
Matrix<T>::~Matrix()
{
    int rowSize = mtrx.size();
    for(int i = 0; i < rowSize; i++)
    {
        mtrx[i].clear();
    }
    mtrx.clear();
}

template<class T>
Matrix<T>  Matrix<T>::operator+(const Matrix<T>& obj)
{
    Matrix<T> res(*this);
    int r1,c1,r2,c2;
    r1 = mtrx.size();
    c1 = mtrx[0].size();
    r2 = obj.mtrx.size();
    c2 = obj.mtrx[0].size();
    if(r1==r2 && c1==c2)
    {
        for(int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            {
                res.mtrx[i][j] += obj.mtrx[i][j];
            }
        }
        return res;
    }
    throw invalid_argument("Cannot add, matrices don't have same dimensions");
}

template<class T>
Matrix<T>  Matrix<T>::operator-(const Matrix<T>& obj)
{
    Matrix<T> res(*this);
    int r1,c1,r2,c2;
    r1 = mtrx.size();
    c1 = mtrx[0].size();
    r2 = obj.mtrx.size();
    c2 = obj.mtrx[0].size();
    if(r1==r2 && c1==c2)
    {
        for(int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            {
                res.mtrx[i][j] -= obj.mtrx[i][j];
            }
        }
        return res;
    }
    throw invalid_argument("Cannot add, matrices don't have same dimensions");
}

template<class T>
Matrix<T>  Matrix<T>::operator*(const Matrix<T>& obj)
{
    Matrix<T> res;
    int r1,c1,r2,c2;
    r1 = mtrx.size();
    c1 = mtrx[0].size();
    r2 = obj.mtrx.size();
    c2 = obj.mtrx[0].size();
    if( c1 == r2)
    {
        for(int i = 0; i < r1; i++)
        {
            vector<T> resCol;
            resCol.resize(c2);
            for(int j = 0; j < c2; j++)
            {
                resCol[j] = 0;
                for(int k = 0; k < c1; k++)
                {
                    resCol[j] += mtrx[i][k] * obj.mtrx[k][j];
                }
            }
            res.mtrx.push_back(resCol);
        }
        return res;
    }
    throw invalid_argument("Cannot add, matrices aren't fit for multiplication");
}

template<class T>
void Matrix<T>::transpose()
{
    Matrix<T> temp(*this);
    int rowSize = mtrx.size();
    int colSize = mtrx[0].size();
    mtrx.resize(colSize);
    for(int i = 0; i < colSize; i++)
    {
        vector<T> row;
        row.resize(rowSize);
        for(int j = 0; j < rowSize; j++)
        {
            row[j] = temp.mtrx[j][i];
        }
        mtrx[i] = row;
    }
}

template<class Temp>
ostream& operator<<(ostream& out, const Matrix<Temp>& obj)
{
    int rowSize = obj.mtrx.size();
    int colSize = obj.mtrx[0].size();
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            out << obj.mtrx[i][j] << " ";
        }
        cout << endl;
    }
    return out;
}

template<class Temp>
istream& operator>>(istream& in, Matrix<Temp>& obj)
{
    int rowSize, columnSize,choice;
    cout << "Enter number of rows: ";
    cin>>rowSize;
    cout << "Enter number of column: ";
    cin>>columnSize;
    cout <<"1 for random data entry"<<endl<<"2 for manual data entry"<<endl<<"choice : ";
    cin>>choice;
    if(choice==1)
    {
        for(int i = 0; i < rowSize; i++)
        {
            vector <Temp> col;
            col.resize(columnSize);
            for(int j = 0; j < columnSize; j++)
            {
                float b = rand() % 100 + 1;
                col[j]= b;
            }
            obj.mtrx.push_back(col);
        }
    }
    else
    {
        for(int i = 0; i < rowSize; i++)
        {
            vector <Temp> col;
            col.resize(columnSize);
            for(int j = 0; j < columnSize; j++)
            {
                //float b = rand() % 100 + 1;
                cin>>col[j];
            }
            obj.mtrx.push_back(col);
        }
    }
    return in;
}
