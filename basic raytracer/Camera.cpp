#include "Camera.h"


Camera::Camera(Canvas& canvas, Vector3& pos, Vector3& direction, double distance) :
    _canvas(canvas),
    viewport(direction*distance),
    position(pos),
    distanceFromViewport(distance)
{
}

SDL_Color Camera::traceRay(int x, int y, double tmax, std::vector<Sphere>& spheres)
{
    Vector3 D = canvasToViewport(x, y);
    double tmin = distanceFromViewport;
    double closestT = std::numeric_limits<double>::max();
    std::vector<Sphere>::iterator closestSphere = spheres.end();

    for (auto sphere = spheres.begin(); sphere != spheres.end(); ++sphere) {
        std::tuple<double, double> t = intersectRaySphere(D, *sphere);
        double t1 = std::get<0>(t);
        double t2 = std::get<1>(t);
        if (t1 >= tmin && t1 <= tmax && t1 < closestT) {
            closestT = t1;
            closestSphere = sphere;
        }
        if (t2 >= tmin && t2 <= tmax && t2 < closestT) {
            closestT = t2;
            closestSphere = sphere;
        }
    }
    if (closestSphere == spheres.end())
        return SDL_Color({ 0xFF, 0xFF, 0xFF, 0xFF });
    return (*closestSphere).getColor();
}

Vector3 Camera::canvasToViewport(int x, int y)
{
    double vx = x * viewport.getWidth() / _canvas.getWidth();
    double vy = y * viewport.getHeight() / _canvas.getHeight();
    return Vector3(vx, vy, distanceFromViewport);
}

std::tuple<double, double> Camera::intersectRaySphere(Vector3 D, Sphere sphere)
{
    constexpr double inf = std::numeric_limits<double>::max();
    double r = sphere.getRadius();
    Vector3 CO = position - sphere.getCenter();

    double a = Vector3::dot(D, D);
    double b = 2 * Vector3::dot(CO, D);
    double c = Vector3::dot(CO, CO) - r * r;
    
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return std::make_tuple(inf, inf);

    double t1 = (-b + SDL_sqrt(discriminant)) / (2 * a);
    double t2 = (-b - SDL_sqrt(discriminant)) / (2 * a);
    return std::make_tuple(t1, t2);
}
