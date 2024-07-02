#ifndef UTILITY_LOAD_FONTS
#define UTILITY_LOAD_FONTS
#include <string>
#include <vector>


const std::string FONTS_DIR_PATH{ "/fonts" };

class FontLoader {
private:
    std::vector<std::string> fontStrings{};
public:
    void loadFonts(std::string_view dirPath);

};

struct Font {

};

#endif /* UTILITY_LOAD_FONTS */
