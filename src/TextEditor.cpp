#include "include/TextEditor.h"
#include "include/Pressable.h"
#include "include/FontLoader.h"
#include <SDL2/SDL.h>
#include <iostream>

TextEditor::TextEditor() {
};

void TextEditor::init(SDL_Renderer* renderer) {
    m_renderer = renderer;

    fontLoader.loadFonts(FONTS_DIR_PATH);
    for (Font each : fontLoader.getFonts()) {
        std::cout << each.fontName << "\n";
    }

}

void TextEditor::handleEvents(SDL_Event* event) {
    switch (event->type)
    {
    case SDL_WINDOWEVENT:
        //Handle Window Resizing events
        switch (event->window.event)
        {
        case SDL_WINDOWEVENT_RESIZED:
        case SDL_WINDOW_SHOWN:
            break;
        default:
            break;
        }
        break;
        //Handle Text input. Input text accessed from event->text.text
    case SDL_TEXTINPUT:
        break;
    case SDL_MOUSEMOTION:
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
    case SDL_MOUSEWHEEL:
        handleMouseEvents(event);
        break;
    default:
        break;
    }


}

void TextEditor::handleMouseEvents(SDL_Event* event) {
    // Sets mouse location.
    SDL_GetMouseState(&mouseLocation.first, &mouseLocation.second);
    switch (event->type) {
    case SDL_MOUSEBUTTONDOWN:
        break;
    case SDL_MOUSEBUTTONUP:
        break;
    case SDL_MOUSEWHEEL:

        scrollAmountY = event->wheel.y;
        break;
    }

}
