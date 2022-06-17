#include "ObiektGeom.hh"



class ProbkaRegolitu:public ObiektGeom
{
public:

 ProbkaRegolitu(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID) : ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID)
  {
    
  }

CollisionType CollisionBool(std::shared_ptr<ObiektGeom>  hoverr)
{
      hoverr;
    return CT_NoCollision;
}
};