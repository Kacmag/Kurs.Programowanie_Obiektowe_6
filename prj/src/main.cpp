#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "Hover.hh"
#include "Kolory.hh"
#include "Scena.hh"

using namespace std;

int main()
{
  srand(time(NULL));
  Vector3D wek;
  {
    Scena sc;
    sc.Rysuj();

    int nr;
    double angle, droga, speed;
    char znak = ' ';

    cout << "j - jazda na wprost" << endl;
    cout << "o - zmien orientacje" << endl;
    cout << "w - wybor lazika" << endl ;
    cout << "m - wyswietl menu" << endl << endl;
    cout << "k - koniec" << endl;
    
    
    while (znak != 'k')
    {
      cout << endl << endl;
      wek.informacje();
      cout << endl << endl;           
      cout << "Aktywny lazik" << endl;
      cout << "               Nazwa: " << sc.nazwa_aktywnego() << endl <<endl;
      cout << "Polozenie (x,y,z): " << sc.polozenie_aktywnego() << endl;
      cin >> znak;
      switch (znak)
      {
      case 'm':
        cout << "j - jazda na wprost" << endl;
        cout << "o - zmien orientacje" << endl;
        cout << "w - wybor lazika" << endl;
        cout << "m - wyswietl menu" << endl;
        break;

      case 'j':
        cout << "podaj droge" << endl;
        cin >> droga;
        cin >> speed;
        sc.Ruch(0, droga, speed);
        break;
      
      case 'o':
        cout << "podaj wartosc kata" << endl;
        cin >> angle;
        sc.Ruch(angle, 0, 0);
        break;
      
      case 'w':
        sc.wypisz();
        cin >> nr;
        sc.wybierz_drona(nr);
        break;
      
      case 'k':
        cout << "koniec" << endl;
        break;
        
      default:
        break;
      }
    }
  }
  cout << endl<< endl;
       
  wek.informacje();

  cout << endl << endl;    
  return 0;
}
