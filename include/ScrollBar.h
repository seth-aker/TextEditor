#ifndef SCROLL_BAR_H
#define SCROLL_BAR_H

#include <SDL2/SDL.h>
//ScrollBar for the right hand side of the text editor.
class ScrollBar {
private:
    SDL_Renderer* renderer = nullptr;
    std::pair<float, float> coordinates;
    std::pair<float, float> dimensions;

public:
    ScrollBar();
    ScrollBar(SDL_Renderer* renderer);
    void render();


};
#endif
