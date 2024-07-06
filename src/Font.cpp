#include "Font.h"
#include <SDL2/SDL_ttf.h>
#include <string>
Font::Font(FontType _fontType, std::string name, std::string path, int size)
    : fontType{ _fontType }, fontName{ name }, filePath{ path }, fontSize{ size }
{
    ttfFont = TTF_OpenFont(path.c_str(), size);
}

// Cleanup the font when destroyed
Font::~Font() {
    if (ttfFont)
        TTF_CloseFont(ttfFont);
}
