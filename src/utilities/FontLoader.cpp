#include "FontLoader.h"
#include "Font.h"
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

FontLoader::FontLoader() {};

bool FontLoader::loadFonts(std::filesystem::path& dirPath) {
    fonts.reserve(36);
    for (const auto& entry : std::filesystem::recursive_directory_iterator(dirPath)) {
        if (entry.path().has_extension() && entry.path().extension().generic_string() == std::string{ ".ttf" }) {

            std::string fontName{ entry.path().filename().generic_string() };
            fonts.push_back(Font{ detectType(entry.path().filename().generic_string()), })
        }

    }
    return true;
}

FontType FontLoader::detectType(const std::string_view fontName) const {
    std::size_t typePos = fontName.find_last_of("-");
    if (typePos == std::string::npos) {
        return FontType::REGULAR;
    }
    std::string_view typeString = fontName.substr(typePos + 1);
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
