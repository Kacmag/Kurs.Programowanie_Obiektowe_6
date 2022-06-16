#include "Scena.hh"

void Scena::Inicjalizuj_Lacze()
{
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X / 2, ROMIAR_POWIERZCHNI_X / 2);
    Lacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y / 2, ROMIAR_POWIERZCHNI_Y / 2);
    Lacze.UstawZakresZ(-0, 90);
    Lacze.UstawRotacjeXZ(40, 60); // Tutaj ustawiany jest widok

    Lacze.Inicjalizuj(); // Tutaj startuje gnuplot.
}

Scena::Scena()
{

    string regolit[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    string nazwy[] = {"FSR", "Perseverance", "Curiosity"};
    Vector3D prze;
    Vector3D skl;
    prze[0] = 70;
    skl[0] = 20;
    skl[1] = 20;
    skl[2] = 10;
    Inicjalizuj_PowierzchnieMarsa(Lacze);

    prze[0] = 70;
    shared_ptr<Hover> Ob1;
    for (int i = 0; i < 3; i++)
    {
        prze[0] = -70 + (35 * i * 2);
        Ob1 = make_shared<Hover>("bryly_wzorcowe/szescian3.dat", nazwy[i].c_str(), i==0 ? Kolor_JasnoNiebieski : Kolor_Czerwony);
        Ob1->set_movement() = prze;
        Ob1->set_scale() = skl;
        lista_obiektow.push_back(Ob1);
    }

    aktualny = Ob1;

    for (int i = 0; i < 10; i++)
    {
        prze[0] = rand() % 180 - 90;
        prze[1] = rand() % 180 - 90;
        skl[0] = 5;
        skl[1] = 5;
        skl[2] = 3;
        shared_ptr<ProbkaRegolitu> p = make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian3.dat", regolit[i].c_str(), Kolor_Czerwony);
        p->set_polozenie() = prze;
        p->set_scale() = skl;
        lista_obiektow.push_back(p);
    }

    DodajDoListyRysowania();
    Inicjalizuj_Lacze();
    Rysuj();
    Lacze.Rysuj();
}

void Scena::wybierz_drona(int n)
{
    int j = 0;
    std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_obiektow.begin();
    for (; j < n; j++, i++)
    {
         aktualny = std::dynamic_pointer_cast<Hover>(*i);
    }
}
void Scena::Ruch(double angle, double droga, double speedd)
{

    aktualny->set_howFar() = droga;
    aktualny->set_speed() = speedd;
    aktualny->set_angle() = angle;
    aktualny->jazda(Lacze);
    aktualny->obr(Lacze);
}

void Scena::Rysuj()
{

    for (std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_obiektow.begin(); i != lista_obiektow.end(); i++)
    {
        (*i)->Przelicz_i_Zapisz_Wierzcholki();
    }
}

void Scena::DodajDoListyRysowania()
{
    PzG::InfoPlikuDoRysowania *wInfoPliku;
    for (std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_obiektow.begin(); i != lista_obiektow.end(); i++)
    {

        wInfoPliku = &Lacze.DodajNazwePliku((*i)->WezNazwePliku_BrylaRysowana());
        wInfoPliku->ZmienKolor((*i)->WezKolorID());
    }
}

void Scena::wypisz()
{
    int j = 0;

    for (std::list<std::shared_ptr<ObiektGeom>>::iterator i = lista_obiektow.begin(); i != lista_obiektow.end(); i++)
    {
        j++;
        std::cout << j << ":" << (*i)->WezNazweObiektu() << std::endl;
    }
}