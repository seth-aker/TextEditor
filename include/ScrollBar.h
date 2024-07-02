#ifndef SCROLL_BAR_H
#define SCROLL_BAR_H

#include "Typedefs.h"
#include <SDL2/SDL.h>
//ScrollBar for the right hand side of the text editor.
class ScrollBar {
private:
    SDL_Renderer* renderer = nullptr;
    Coordinates coordinates;
    Dimensions dimensions;

public:
    ScrollBar();
    ScrollBar(SDL_Renderer* renderer);
    void render();


};
#endif
