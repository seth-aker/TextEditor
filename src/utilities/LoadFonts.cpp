#include "LoadFonts.h"
#include <vector>
#include <string>
#include <filesystem>

void FontLoader::loadFonts(std::string_view dirPath) {
    fontStrings.reserve(10);
    for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
        fontStrings.emplace_back(entry.path().generic_string());
    }
}
