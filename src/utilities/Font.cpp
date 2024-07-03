#include "Font.h"
#include <string>
Font::Font(FontType _fontType, std::string name, std::string path, int size)
    : fontType{ _fontType }, fontName{ name }, filePath{ path }, fontSize{
    size
    }
{}
