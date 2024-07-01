#include "TextEditor.h"
#include "Pressable.h"
#include <SDL2/SDL.h>

TextEditor::TextEditor() {};

void TextEditor::init(SDL_Renderer* renderer) {
    m_renderer = renderer;
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
    case SDL_MOUSEBUTTONUP:
        break;
    case SDL_MOUSEBUTTONDOWN:
        break;
    case SDL_MOUSEWHEEL:

    default:
        break;
    }

}
