#ifndef MATRIX_HH
#define MATRIX_HH


#include "Vector.hh"
#include <algorithm>
#include <iostream>

template <class S_Type, int S_Size>
class Matrix {

        Vector<S_Type,S_Size>  Tablica[S_Size];


        S_Type Wyznacznik;

        public:

        Vector<S_Type,S_Size> operator[](int i) const;
        Vector<S_Type,S_Size> &operator[](int i);
        

        S_Type get_Wyznacznik()const{return Wyznacznik;};
        void gausMethod();
        void podmianaWiersza(Vector<S_Type,S_Size> wek, int i);
        Vector<S_Type,S_Size> operator*(Vector<S_Type,S_Size> Skl);
    
        
};


template <class S_Type, int S_Size>
std::istream &operator>>(std::istream &Strm, Matrix<S_Type,S_Size> &Matriks)
{
    for (int i = 0; i < S_Size; i++)
        Strm >> Matriks[i];
    return Strm;
}


template <class S_Type, int S_Size>
std::ostream &operator<<(std::ostream &Strm, const Matrix<S_Type,S_Size> &Matriks)
{
    for (int i = 0; i < S_Size; i++)
        {
        Strm << Matriks[i] << endl;
        }
    return Strm;
}




template <class S_Type, int S_Size>
Vector<S_Type,S_Size>  Matrix<S_Type,S_Size> ::operator[](int i) const
{
    return Tablica[i];
}

template <class S_Type, int S_Size>
Vector<S_Type,S_Size> &Matrix<S_Type,S_Size>::operator[](int i)
{
    return Tablica[i];
}

template <class S_Type, int S_Size>
void Matrix<S_Type,S_Size>::gausMethod()
{
    Matrix pomoc=*this;
    int a = 1;
    S_Type suma={1};
    for (int i = 0; i < S_Size; i++)
    {
        for (int j = i + 1; j < S_Size; j++)
        {
            
            if (pomoc[i][i] == 0)
            {
                for (int k = i + 1; k < S_Size; k++)
                {
                    if (pomoc[k][i] != 0)
                    {
                    std::swap(pomoc[i], pomoc[k]);
                    a*=-1;
                    }
                    else
                    {
                    break;
                    }
                }             
            }
            else
            {
                
                S_Type dzielnik;
                Vector<S_Type,S_Size> wek;
                for(int t = i + 1; t < S_Size; t++)
                {
                        dzielnik=pomoc[t][i]/pomoc[i][i];
                        wek=pomoc[i]*dzielnik;
                        pomoc[t]=pomoc[t]-wek;

                }
            
            } 
        }
    }
    for (int i = 0; i < S_Size; i++)
    {
        suma=suma*pomoc[i][i];
    }
    
    suma=(suma*a);
    Wyznacznik=suma;
    
}


template <class S_Type, int S_Size>
Vector<S_Type,S_Size> Matrix<S_Type,S_Size>::operator*(Vector<S_Type,S_Size> Skl)
 {
        Vector<S_Type,S_Size> wynik;
        Vector<S_Type,S_Size> suma;
                for(int i=0; i<S_Size; i++)
                {
                        suma=suma+Tablica[i]*Skl[i];
                } 
        wynik=suma;
        return wynik;
 }




template <class S_Type, int S_Size>
void Matrix<S_Type,S_Size>::podmianaWiersza(Vector<S_Type,S_Size> wek, int i)
{
    Tablica[i]=wek;
}



#endif
