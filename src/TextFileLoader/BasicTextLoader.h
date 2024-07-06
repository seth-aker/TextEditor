#ifndef BASIC_TEXT_LOADER_H
#define BASIC_TEXT_LOADER_H
#include "IFileLoader.h"
#include <string>
#include <fstream>
class BasicTextLoader : public IFileLoader {
public:
    virtual std::string getFile(std::string& filePath) override;
    virtual bool saveFile(const std::string& data, const std::string& filePath) override;
    BasicTextLoader();
protected:
};
#endif /* BASIC_TEXT_LOADER_H */
