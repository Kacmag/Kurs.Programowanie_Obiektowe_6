#include "Matrix3D.hh"

Matrix3D rotZ(double angle)
{
    Matrix3D Wynik;
    double rad=angle*M_PI/180;
    Wynik[0][0] = cos(rad);
    Wynik[0][1] = -sin(rad);
    Wynik[0][2] = 0;
    Wynik[1][0] = sin(rad);
    Wynik[1][1] = cos(rad);
    Wynik[1][2] = 0;
    Wynik[2][0] = 0;
    Wynik[2][1] = 0;
    Wynik[2][2] = 1;

    return Wynik;
}
