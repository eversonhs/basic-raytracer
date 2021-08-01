#include "Canvas.h"

Canvas::Canvas(const char * title, int wWidth, int wHeight) :
    windowTitle(title),
    windowWidth(wWidth),
    windowHeight(wHeight),
    isRunning(false),
    window(nullptr),
    renderer(nullptr)
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
    isRunning = true;
    return isRunning;
}

void Canvas::putPixel(SDL_Color color, int x, int y) {
    std::tuple<int, int> p = canvasToOrigin(x, y);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, std::get<0>(p), std::get<1>(p));
}

void Canvas::update() {
    SDL_RenderPresent(renderer);
}

void Canvas::wait()
{
    while (isRunning) 
    {
        processInput();
    }
}

int Canvas::getWidth() const
{
    return windowWidth;
}

int Canvas::getHeight() const
{
    return windowHeight;
}

std::tuple<int, int> Canvas::canvasToOrigin(int x, int y)
{
    int px = (windowWidth / 2) + x;
    int py = (windowHeight / 2) - y;
    return std::make_tuple(px, py);
}

void Canvas::processInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }
    }
}
