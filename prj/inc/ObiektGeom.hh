#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <vector>
#include <string>
#include "UkladWsp.hh"
#include "CollisionType.hh"
#include "ObrysXY.hh"
#include <memory>

using namespace std;

class Hover;

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA "pliki_do_rysowania"

class ObiektGeom:  public UkladWsp
{

  string _NazwaPliku_BrylaWzorcowa;
  string _NazwaPliku_BrylaRysowana;
  string _NazwaObiektu;

  int _KolorID;
  double angle_zadany;

  Vector3D przesun;
  Matrix3D macierz_obr;
  ObrysXY obrys;

public:

  ObiektGeom() {     
  
      for(int i=0; i<3; i++)
       macierz_obr[i][i]=1;
       }


  ObrysXY get_obrys() { return obrys; }
  bool przeciecie(ObrysXY obrys_p)
  {
    ObrysXY W;

   

    Vector2D dl1 = obrys.get_LeftBottom();
    Vector2D gp1 = obrys.get_RightUp();

    Vector2D dl2 = obrys_p.get_LeftBottom();
    Vector2D gp2 = obrys_p.get_RightUp();
   
    if (dl1[0] > dl2[0] && dl1[0] < gp2[0] && dl1[1] > dl2[1] && dl1[1] < gp2[1])
    {
      return true;
    }

    if (gp1[0] > dl2[0] && gp1[0] < gp2[0] && gp1[1] > dl2[1] && gp1[1] < gp2[1])
    {
      return true;
    }

    if (dl1[0] > dl2[0] && dl1[0] < gp2[0] && gp1[1] > dl2[1] && gp1[1] < gp2[1])
    {
      return true;
    }

    if (gp1[0] > dl2[0] && gp1[0] < gp2[0] && dl1[1] > dl2[1] && dl1[1] < gp2[1])
    {
      return true;
    }
    
    return false;
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

  Matrix3D &set_Matrix(){return  macierz_obr;}
  Matrix3D get_macierz()const{return  macierz_obr;}
  

  const std::string &WezNazweObiektu() const { return _NazwaObiektu; }
  const std::string &WezNazwePliku_BrylaRysowana() const { return _NazwaPliku_BrylaRysowana; }

  Vector3D &set_scale() { return  set_Scale(); }
  Vector3D &set_movement() { return  przesun; }

  bool Przelicz_i_Zapisz_Wierzcholki(std::ostream &StrmWy, std::istream &StrmWe);
  bool Przelicz_i_Zapisz_Wierzcholki();

  virtual CollisionType CollisionBool(std::shared_ptr<ObiektGeom> hoverr) = 0;
};

#endif
