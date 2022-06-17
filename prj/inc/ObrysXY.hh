#include <iostream>
#include "Vector2D.hh"

class ObrysXY
{
    Vector2D LeftBottom;
    Vector2D RightUp;

public:
    Vector2D get_LeftBottom() const { return LeftBottom; }
    Vector2D &set_LeftBottom() { return LeftBottom; }
    Vector2D get_RightUp() const { return RightUp; }
    Vector2D &set_RightUp() { return RightUp; }
};