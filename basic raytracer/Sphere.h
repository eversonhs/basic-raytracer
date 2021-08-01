#pragma once
#include"Vector3.h"
#include<SDL2/SDL.h>
class Sphere {
public:
    Sphere(Vector3& c, double rd, SDL_Color col);
    Sphere(Vector3&& c, double rd, SDL_Color col);

    //TODO: Refactor
    SDL_Color getColor();
    Vector3 getCenter();
    double getRadius();

private:
    Vector3 center;
    double radius;
    SDL_Color color;
};

