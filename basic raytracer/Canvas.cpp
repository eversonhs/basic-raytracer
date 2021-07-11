#include "Canvas.h"

Canvas::Canvas(const char * title, Uint32 wWidth, Uint32 wHeight) :
    windowTitle(title), windowWidth(wWidth), windowHeight(wHeight),
    window(nullptr), renderer(nullptr)
{}

Canvas::~Canvas() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Canvas::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Error: Unable to intialize SDL video subsystem. ERROR: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(
        windowTitle.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        windowWidth,
        windowHeight,
        0);
    if (window == NULL) {
        SDL_Log("Error: Unable to create an window. ERROR: %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_Log("Error: Unable to create a renderer. ERROR: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Canvas::putPixel(SDL_Color color, int x, int y) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, x, y);
}

void Canvas::update() {
    SDL_RenderPresent(renderer);
}
