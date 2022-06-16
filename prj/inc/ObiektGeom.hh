#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include "UkladWsp.hh"
#include "CollisionType.hh"
#include <memory>

using namespace std;

class Hover;

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA "pliki_do_rysowania"

class ObiektGeom:  public UkladWsp
{

  /* potrzebne do  sposob 2 inicjalizacji zmiennych  protected: */
  string _NazwaPliku_BrylaWzorcowa;
  string _NazwaPliku_BrylaRysowana;
  string _NazwaObiektu;

  int _KolorID;
  double angle_zadany;

  Vector3D przesun;
  matrix_3D matrix_obr;
public:

  ObiektGeom() {     
  
      for(int i=0; i<3; i++)
       matrix_obr[i][i]=1;
       }


  // @brief funkcja GeometricOBJ ustawiajaca parametry obiektu do wyrysowania
  // @param sNazwaPliku_BrylaWzorcowa przyjmuje wskaznik na char
  // @param sNazwaObiektu przyjmuje wskaznik na char
  // @param KolorID 

  ObiektGeom(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID);

  double &set_angle_zadany(){return angle_zadany;}
  int WezKolorID() const { return _KolorID; }

  Vector3D &set_polozenie(){return  przesun;}
  Vector3D get_polozenie()const {return  przesun;}

  matrix_3D &set_Matrix(){return  matrix_obr;}
  matrix_3D get_macierz()const{return  matrix_obr;}
  

  const std::string &WezNazweObiektu() const { return _NazwaObiektu; }
  const std::string &WezNazwePliku_BrylaRysowana() const { return _NazwaPliku_BrylaRysowana; }

  Vector3D &set_scale() { return  set_Scale(); }
  Vector3D &set_movement() { return  przesun; }

  bool Przelicz_i_Zapisz_Wierzcholki(std::ostream &StrmWy, std::istream &StrmWe);
  bool Przelicz_i_Zapisz_Wierzcholki();
  
  virtual CollisionType CollisionBool(std::shared_ptr<Hover> & hoverr)=0;
};

#endif
