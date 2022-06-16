#ifndef SCENA_HH
#define SCENA_HH
#include "Hover.hh"
#include "Kolory.hh"
#include "ProbkaRegolitu.hh"
#include "PowierzchniaMarsa.hh"
#include <list>
#include <memory>
#include "lacze_do_gnuplota.hh"
#include <unistd.h>

class Scena
{
    PzG::LaczeDoGNUPlota Lacze;
    std::shared_ptr<Hover> aktualny;
    std::list<std::shared_ptr<ObiektGeom>> lista_obiektow;

    void Inicjalizuj_Lacze();

public:
    Scena();
    
    std::string nazwa_aktywnego(){return aktualny->WezNazweObiektu();}
    Vector3D polozenie_aktywnego(){return aktualny->get_polozenie();}
    
    void Rysuj();
    void Ruch(double angle, double droga, double speedd);
    void wybierz_drona(int n);
    void DodajDoListyRysowania();
    void wypisz();
};
#endif