#include "../include/FontLoader.h"
#include "../include/Font.h"
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

FontLoader::FontLoader() {};

bool FontLoader::loadFonts(std::filesystem::path& dirPath) {
    fonts.reserve(36);
    for (const auto& entry : std::filesystem::recursive_directory_iterator(dirPath)) {
        if (entry.path().has_extension() && entry.path().extension().generic_string() == std::string{ ".ttf" }) {
            std::string_view fileText = entry.path().filename().generic_string();
            fonts.push_back(Font{ detectType(fileText), getFontName(fileText), entry.path().generic_string() });
        }

    }
    return true;
}

FontType FontLoader::detectType(const std::string_view fontText) const {
    std::size_t typePos = fontText.find_last_of("-");
    if (typePos == std::string::npos) {
        return FontType::REGULAR;
    }
    std::string_view typeString = fontText.substr(typePos + 1);
    if (typeString == "Regular.ttf") {
        return FontType::REGULAR;
    }
    else if (typeString == "Bold.ttf") {
        return FontType::BOLD;
    }
    else if (typeString == "Italic.ttf") {
        return FontType::ITALIC;
    }
    else if (typeString == "BoldItalic.ttf") {
        return FontType::BOLDITALIC;
    }

    throw "Error: Font Not Recognized";

}

std::string FontLoader::getFontName(const std::string_view fontText) const {
    std::size_t typePos = fontText.find_last_of("-");
    std::string fontName{ fontText.substr(0, typePos) };
    return fontName;
}
