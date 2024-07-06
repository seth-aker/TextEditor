#ifndef UTILITY_FONT_H
#define UTILITY_FONT_H
#include <SDL2/SDL_ttf.h>
#include <string>
enum FontType {
    REGULAR,
    BOLD,
    ITALIC,
    BOLDITALIC
};
struct Font {
    TTF_Font* ttfFont = nullptr;
    const FontType fontType;
    const std::string fontName;
    const std::string filePath;
    int fontSize;
    Font(FontType _fontType, std::string name, std::string path, int fontSize = 11);
    ~Font();
};

#endif /* UTILITY_FONT_H */
