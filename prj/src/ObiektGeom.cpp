#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"

using namespace std;

ObiektGeom::ObiektGeom(const char *sNazwaPliku_BrylaWzorcowa,
                       const char *sNazwaObiektu,
                       int KolorID) : _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
 
  for (int i = 0; i < 3; i++)
    matrix_obr[i][i] = 1;
  angle_zadany = 0;
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(std::ostream &StrmWy, std::istream &StrmWe)
{

  int Indeks_Wiersza = 0;

  StrmWe >> set_wsp();
  if (StrmWe.fail())
    return false;

  do
  {
    set_wsp() = (get_wsp() & get_Skala()) + przesun;

    StrmWy << get_wsp() << endl;
    ++Indeks_Wiersza;

    if (Indeks_Wiersza >= 4)
    {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }

    StrmWe >> set_wsp();

  } while (!StrmWe.fail());

  if (!StrmWe.eof())
    return false;

  return Indeks_Wiersza == 0 && !StrmWy.fail();
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
  ifstream StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open()))
  {
    cerr << endl
         << "Nie mozna otworzyc jednego z plikow:" << endl
         << "    " << _NazwaPliku_BrylaWzorcowa << endl
         << "    " << _NazwaPliku_BrylaRysowana << endl
         << endl;
    return false;
  }

  int Indeks_Wiersza = 0;

  StrmWe >> set_wsp();

  if (StrmWe.fail())
    return false;

  do
  {

    set_wsp() = matrix_obr * get_wsp();
   
    set_wsp() = (get_wsp() & get_Skala()) + przesun;

    StrmWy << get_wsp() << endl;
    ++Indeks_Wiersza;

    if (Indeks_Wiersza >= 4)
    {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }

    StrmWe >> set_wsp();
    ;
  } while (!StrmWe.fail());

  if (!StrmWe.eof())
    return false;

  angle_zadany = 0;
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}
