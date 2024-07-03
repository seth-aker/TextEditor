#include "FontLoader.h"
#include "Font.h"
#include <vector>
#include <string>
#include <filesystem>

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

}
