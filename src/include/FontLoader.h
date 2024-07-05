#ifndef UTILITY_LOAD_FONTS
#define UTILITY_LOAD_FONTS
#include "Font.h"

#include <string>
#include <vector>
#include <filesystem>


static const std::filesystem::path FONTS_DIR_PATH{ "C:\\Users\\14807\\workspace\\cpp\\TextEditor\\fonts" };

class FontLoader {
private:
    std::vector<Font> fonts{};
    FontType detectType(const std::string_view fontText) const;
    std::string getFontName(const std::string_view fontText) const;
public:
    bool loadFonts(const std::filesystem::path& dirPath);
    FontLoader();
    std::vector<Font> getFonts();
};



#endif /* UTILITY_LOAD_FONTS */
