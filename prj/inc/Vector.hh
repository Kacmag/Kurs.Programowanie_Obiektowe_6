#ifndef VECTOR_HH
#define VECTOR_HH


#include <iostream>

using namespace std;

template <class S_Type, int S_Size>
class Vector
{
    static int wszystkie;
    static int aktualne;
    S_Type Tablica[S_Size];

public:
    Vector(const Vector &wek);
    S_Type get_Tablica(int i) const;
    S_Type& set_Tablica(int i);
    S_Type operator[](int i) const;
    S_Type& operator[](int i);
    S_Type operator*(Vector const Skl);

    Vector operator+(Vector const Skl);
    Vector operator-(Vector const Skl);    
    Vector operator*(S_Type const Skl);
    Vector operator/(S_Type const Skl);
    Vector operator&(Vector const Skl);
    void informacje();
    constexpr Vector<S_Type, S_Size>& operator=(const Vector<S_Type, S_Size>& wek);
    Vector();
    ~Vector();  
    
};

template <class S_Type, int S_Size>
constexpr Vector<S_Type, S_Size>& Vector<S_Type, S_Size>::operator=(const Vector<S_Type, S_Size>&wek)
{
    for (int i = 0; i < S_Size; i++)
        Tablica[i] = wek.Tablica[i];
    return *this;
}


template <class S_Type, int S_Size>
Vector<S_Type, S_Size>::Vector()
{
    for (int i = 0; i < S_Size; i++)
        Tablica[i] = 0;
    aktualne++;
    wszystkie++;
}

template <class S_Type, int S_Size>
Vector<S_Type, S_Size>::~Vector()
{
    aktualne--;
}

template <class S_Type, int S_Size>
Vector<S_Type, S_Size>::Vector(const Vector<S_Type, S_Size> &wek)
{
    for (int i = 0; i < S_Size; i++)
        Tablica[i] = wek.Tablica[i];

    aktualne++;
}
template <class S_Type, int S_Size>
int Vector<S_Type, S_Size>::wszystkie = 0;

template <class S_Type, int S_Size>
int Vector<S_Type, S_Size>::aktualne = 0;

template <class S_Type, int S_Size>
void Vector<S_Type, S_Size>::informacje()
{
    cout << "Aktualna ilosc obiektow Wektor3D: " << aktualne << endl;
    cout << "Laczna ilosc obiektow Wektor3D: " << wszystkie << endl;
}

template <class S_Type, int S_Size>
std::istream& operator>>(std::istream& Strm, Vector<S_Type, S_Size>& wek)
{
    for (int i = 0; i < S_Size; i++)
    {
        Strm >> wek[i];
    }

    return Strm;
}
template <class S_Type, int S_Size>
std::ostream& operator<<(std::ostream& Strm, const Vector<S_Type, S_Size>& wek)
{
    for (int i = 0; i < S_Size; i++)
        Strm << wek[i] << " ";

    return Strm;
}

template <class S_Type, int S_Size>
S_Type Vector<S_Type,S_Size>::get_Tablica(int i) const
{
    return Tablica[i];
}



template <class S_Type, int S_Size>
S_Type &Vector<S_Type,S_Size>::set_Tablica(int i)
{
    return Tablica[i];
}



template <class S_Type, int S_Size>
S_Type Vector<S_Type,S_Size>::operator*(Vector<S_Type,S_Size> const Skl)
{
    double Wynik = 0;
    for (int i = 0; i < S_Size; i++)
        Wynik += Tablica[i] * Skl[i];

    return Wynik;
}

template <class S_Type, int S_Size>
Vector<S_Type,S_Size> Vector<S_Type,S_Size>::operator&(Vector const Skl)
{
        Vector Wynik;
    for (int i = 0; i < S_Size; i++)
        Wynik[i] = Tablica[i] * Skl[i];

    return Wynik;
}

template <class S_Type, int S_Size>
Vector<S_Type,S_Size> Vector<S_Type,S_Size>::operator*(S_Type const Skl)
{
    Vector Wynik;
    for (int i = 0; i < S_Size; i++)
        Wynik[i] = Tablica[i] * Skl;

    return Wynik;
}



template <class S_Type, int S_Size>
Vector<S_Type,S_Size> Vector<S_Type,S_Size>::operator/(S_Type const Skl)
{
    Vector Wynik;
    for (int i = 0; i < S_Size; i++)
        Wynik[i] = Tablica[i] / Skl;

    return Wynik;
}


template <class S_Type, int S_Size>
S_Type Vector<S_Type,S_Size>::operator[](int i) const
{
    if (i >= 0 && i < S_Size)
        return Tablica[i];
    else
        cerr << "Blad indexu" << endl;
    return Tablica[i];
}



template <class S_Type, int S_Size>
S_Type &Vector<S_Type,S_Size>::operator[](int i)
{
    if (i >= 0 && i < S_Size)
        return Tablica[i];
    else
        cerr << "Blad indexu" << endl;
    return  Tablica[i];
}



template <class S_Type, int S_Size>
Vector<S_Type,S_Size> Vector<S_Type,S_Size>::operator+(Vector<S_Type,S_Size> const Skl)
{
    Vector Wynik;
    for (int i = 0; i < S_Size; i++)
        Wynik[i] = Tablica[i] + Skl[i];

    return Wynik;
}



template <class S_Type, int S_Size>
Vector<S_Type,S_Size> Vector<S_Type,S_Size>::operator-(Vector<S_Type,S_Size> const Skl)
{
    Vector Wynik;
    for (int i = 0; i < S_Size; i++)
        Wynik[i] = Tablica[i] - Skl[i];

    return Wynik;
}




#endif
