#pragma once
#include <memory>
#include <unistd.h>
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"
class Hover : public ObiektGeom
{

  double howFar;
  double speed;
  double angle;
  double angle_wypadkowy;


public:
  
  CollisionType CollisionBool(std::shared_ptr<ObiektGeom> l)
  {
   
    if (przeciecie((*l).get_obrys()))
    {
      return CT_Collision;
    }
    return CT_NoCollision;
  }
  Hover()
  {
    angle_wypadkowy = 0;
  }
  Hover(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID) : ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID)
  {
    angle_wypadkowy = 0;
  }


  void jazda(PzG::LaczeDoGNUPlota &lacze,std::shared_ptr<Hover> aktulany, std::list<std::shared_ptr<ObiektGeom>> &lista_obiektow)
  {
    Vector3D wek;
    wek[1] = speed;

    for (double i = 0; i < howFar; i += speed)
    {
      for (std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_obiektow.begin(); i != lista_obiektow.end(); i++)
      {
        if ( aktulany != (std::dynamic_pointer_cast<Hover>(*i)))
        {
            
          if (CollisionBool((*i)) == CT_Collision)
          {
            cout<<endl;
            cout<<"Kolizja z: ";
            cout<<(*i)->WezNazweObiektu()<<endl<<endl;            
            cout << "     -----  K o L i Z j A -----" << endl;
            return;
          }
        }
      }
      set_polozenie() = get_polozenie() + (rotZ(angle_wypadkowy) * wek);
      Przelicz_i_Zapisz_Wierzcholki();
      lacze.Rysuj();
      usleep(10000);
    }
  }

  void obr()
  {

    angle_wypadkowy += 1;
    set_Matrix() = rotZ(angle_wypadkowy);
    if (angle_wypadkowy == 360)
    {
      angle_wypadkowy = 0;
    }
  }
  void obr_2()
  {

    angle_wypadkowy -= 1;
    set_Matrix() = rotZ(angle_wypadkowy);
    if (angle_wypadkowy == -360)
    {
      angle_wypadkowy = 0;
    }
  }

 void obr(PzG::LaczeDoGNUPlota &lacze)
  {

    for (int i = 0; i < angle; i++)
    {
      obr();
      Przelicz_i_Zapisz_Wierzcholki();
      lacze.Rysuj();
      usleep(10000);
    }

    for (int i = angle; i < 0; i++)
    {
      obr_2();
      Przelicz_i_Zapisz_Wierzcholki();
      lacze.Rysuj();
      usleep(10000);
    }
  }
  //@return - zwraca kat lazika


  double get_howFar() const { return howFar; }
  //@return - zwraca atrybut odleglosci


  double get_speed() const { return speed; }
  //@return - zwraca atrybut predkosci


  double &set_angle() { return angle; }
  //@brief - funkcja dostępowa
  //@return - zwraca referencje kata
  

  double &set_howFar() { return howFar; }
  //@brief - funkcja dostępowa
  //@return - zwraca oryginal odleglosc

  
  double &set_speed() { return speed; }
  //@brief - funkcja dostępowa
  //@return - zwraca oryginal zmiennej predkosci
};


  