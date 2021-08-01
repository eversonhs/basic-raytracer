#include "Viewport.h"

Viewport::Viewport(Vector3& pos) :
    position(pos),
    height(1.0),
    width(1.0)
{
}

double Viewport::getHeight() const
{
    return height;
}

double Viewport::getWidth() const
{
    return width;
}
