#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include "Typedefs.h"
#include "ScrollBar.h"
#include "FontLoader.h"
#include "TextFileLoader/IFileLoader.h"
#include "TextFileLoader/BasicTextLoader.h"

#include <SDL2/SDL.h>

#include <string>
#include <memory>

const std::string DOCUMENTS_LOCATION{ "C:\\Users\\14807\\workspace\\cpp\\TextEditor\\documents\\" };
class TextEditor {
private:
    SDL_Renderer* m_renderer = nullptr;
    FontLoader m_fontLoader{};
    std::unique_ptr<IFileLoader> m_textLoader = nullptr;

    //ScrollBar m_scrollbar;
    int scrollAmountY{ 0 };
    Coordinates mouseLocation{ 0.0, 0.0 };
    bool lMouseClicked{ false };
    std::string rawText{ "This is a raw text document" };
    std::string docName{ "default.txt" };

    void handleMouseEvents(SDL_Event* event);
    void setDocFilePath(const std::string& path);
    bool saveDocument();


public:
    TextEditor();
    void init(SDL_Renderer* renderer);
    void handleEvents(SDL_Event* event);
    void render();

};

#endif /* TEXT_EDITOR_H */
