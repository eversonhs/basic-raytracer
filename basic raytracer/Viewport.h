#pragma once
#include"Vector3.h"
class Viewport
{
public:
    Viewport(Vector3& pos);

    double getHeight() const;
    double getWidth() const;
private:
    Vector3 position;
    double height;
    double width;

};

