#pragma once
#ifndef CANVAS_H
#define CANVAS_H

#include<SDL2/SDL.h>
#include<string>
#include<tuple>
class Canvas
{
public:
    Canvas(const char* title, int wWidth, int wHeight);
    ~Canvas();

    bool init();

    void putPixel(SDL_Color color, int x, int y);
    void update();
    void wait();

    int getWidth() const;
    int getHeight() const;
private:
    std::string windowTitle;
    int windowWidth, windowHeight;
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

    //TODO: This method need a better name
    std::tuple<int,int> canvasToOrigin(int x, int y);
    void processInput();
};

#endif // !CANVAS_H

