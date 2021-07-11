#include<iostream>
#include"Canvas.h"

int main(int argc, char* argv[]) {
    Canvas c("Minha Janela", 800, 600);
    if (c.init())
        SDL_Delay(1000);
    
    return 0;
}