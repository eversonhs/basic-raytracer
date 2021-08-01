#include "Sphere.h"

Sphere::Sphere(Vector3& c, double rd, SDL_Color col) :
    center(c), radius(rd), color(col)
{
}

Sphere::Sphere(Vector3&& c, double rd, SDL_Color col) :
    center(c), radius(rd), color(col)
{
}

SDL_Color Sphere::getColor()
{
    return color;
}

Vector3 Sphere::getCenter()
{
    return center;
}

double Sphere::getRadius()
{
    return radius;
}
