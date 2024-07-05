#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H
#include "Typedefs.h"
#include "ScrollBar.h"
#include <SDL2/SDL.h>

class TextEditor {
private:
    SDL_Renderer* m_renderer = nullptr;
    //ScrollBar m_scrollbar;
    int scrollAmountY{ 0 };
    Coordinates mouseLocation{ 0.0, 0.0 };
    bool lMouseClicked{ false };

    void handleMouseEvents(SDL_Event* event);



public:
    TextEditor(SDL_Renderer* renderer);
    void init(SDL_Renderer* renderer);
    void handleEvents(SDL_Event* event);
    void render();

};

#endif /* TEXT_EDITOR_H */
