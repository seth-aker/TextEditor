#include "src/TextEditor.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <memory>
#include <crtdbg.h>
#include <iostream>
#include <fstream>

#ifndef WINDOW_HEIGHT
#   define WINDOW_HEIGHT 480
#endif /*WINDOW_HEIGHT*/
#ifndef WINDOW_WIDTH
#   define WINDOW_WIDTH 640
#endif /*WINDOW_WIDTH*/


int main(int argc, char* argv[]) {
    bool exitProg = false;

#if defined _DEBUG || defined DEBUG
    _CrtSetBreakAlloc(0);
    atexit(
        []() {
            if (!!_CrtDumpMemoryLeaks()) {
                fprintf(stderr, "Memory leak!\n");

                _CrtDbgBreak();
            }
        }
    );
#endif

    // Create the SDL_Resources
    SDL_Window* window = SDL_CreateWindow("A Text Editor",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    if (!window) {
        std::cerr << "Error creating window: " << SDL_GetError();
        exitProg = true;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cerr << "Error creating renderer: " << SDL_GetError();
        exitProg = true;
    }
    SDL_Cursor* cursorArrow = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
    SDL_Cursor* cursorInput = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);

    if (!cursorArrow || !cursorInput) {
        std::cerr << "Error creating cursors: " << SDL_GetError();
        exitProg = true;
    }
    SDL_ShowCursor(SDL_ENABLE);

    // Set up the text editor here
    TextEditor textEdit{};
    textEdit.init(renderer);


    SDL_Event event;
    while (!exitProg) {
        //Register occurring events
        while (SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                exitProg = true;
                break;
            default:
                textEdit.handleEvents(&event);
                break;
            }
        }
        // Background white
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        textEdit.render();

    }
    // Cleanup
    if (cursorInput)
        SDL_FreeCursor(cursorInput);
    if (cursorArrow)
        SDL_FreeCursor(cursorArrow);
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);

    return 0;
}
