#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H
#include "ScrollBar.h"
#include <SDL2/SDL.h>

class TextEditor {
private:
    SDL_Renderer* m_renderer = nullptr;
    ScrollBar m_scrollbar;


public:
    TextEditor();
    void init(SDL_Renderer* renderer);
    void handleEvents(SDL_Event* event);
    void render();

};

#endif /* TEXT_EDITOR_H */
