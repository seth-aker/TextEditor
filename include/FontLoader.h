#ifndef UTILITY_LOAD_FONTS
#define UTILITY_LOAD_FONTS
#include "Font.h"

#include <string>
#include <vector>
#include <filesystem>


static const std::string FONTS_DIR_PATH{ "C:\\Users\\14807\\workspace\\cpp\\TextEditor\\fonts" };

class FontLoader {
private:
    std::vector<Font> fonts{};
    FontType detectType(const std::string_view) const;
public:
    bool loadFonts(std::filesystem::path& dirPath);
    FontLoader();
};



#endif /* UTILITY_LOAD_FONTS */
