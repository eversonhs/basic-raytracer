#include<iostream>
#include<vector>
#include"Vector3.h"
#include"Canvas.h"
#include"Camera.h"
#include"Sphere.h"

int main(int argc, char* argv[]) {
    Canvas c("Minha Janela", 800, 600);
    Camera camera(c, Vector3::zero, Vector3::forward, 1.0);

    Sphere s1(
        Vector3(0.0, -1.0, 3.0),
        1.0,
        { 0xFF, 0x00, 0x00, 0xFF }
    );
    Sphere s2(
        Vector3(-2.0, 0.0, 4.0),
        1.0,
        { 0x00, 0xFF, 0x00, 0xFF }
    );
    Sphere s3(
        Vector3(2.0, 0.0, 4.0),
        1.0,
        { 0x00, 0x00, 0xFF, 0xFF }
    );
    std::vector<Sphere> spheres;
    spheres.push_back(s1);
    spheres.push_back(s2);
    spheres.push_back(s3);

    constexpr double inf = std::numeric_limits<double>::max();
    if (c.init()) {
        for (int x = -c.getWidth() / 2; x <= c.getWidth(); x++) {
            for (int y = -c.getHeight() / 2; y <= c.getHeight() / 2; y++) {
                SDL_Color color = camera.traceRay(x, y, inf, spheres);
                c.putPixel(color, x, y);
            }
        }
        c.update();
        c.wait();
    }
        
    
    return 0;
}