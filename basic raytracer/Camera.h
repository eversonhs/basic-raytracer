#pragma once
#include "Vector3.h"
#include "Viewport.h"
#include "Canvas.h"
#include "Sphere.h"
#include <SDL2/SDL.h>
#include <limits>
#include <tuple>
#include <vector>

class Camera
{
public:

    Camera(Canvas& canvas, Vector3& pos, Vector3& direction, double distance);

    SDL_Color traceRay(int x, int y, double tmax, std::vector<Sphere>& spheres);

private:
    Canvas& _canvas;
    Viewport viewport;
    Vector3 position;
    double distanceFromViewport;
    
    Vector3 canvasToViewport(int x, int y);

    std::tuple<double, double> intersectRaySphere(Vector3 D, Sphere sphere);
};

