#include "Vector3D.hh"
#include "Matrix3D.hh"



class UkladWsp
{
  Vector3D wsp;
  Vector3D Skala;

  public:
  Vector3D get_wsp()const{return wsp;}
  Vector3D &set_wsp(){return wsp;}
  Vector3D get_Skala()const{return Skala;}
  Vector3D &set_Scale(){return Skala;}

};

