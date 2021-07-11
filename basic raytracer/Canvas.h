#pragma once
#ifndef CANVAS_H
#define CANVAS_H

#include<SDL2/SDL.h>
#include<string>
class Canvas
{
public:
    Canvas(const char* title, Uint32 wWidth, Uint32 wHeight);
    ~Canvas();

    bool init();

    void putPixel(SDL_Color color, int x, int y);
    void update();
private:
    std::string windowTitle;
    Uint32 windowWidth, windowHeight;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif // !CANVAS_H

