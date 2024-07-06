#ifndef I_FILE_LOADER_H
#define I_FILE_LOADER_H
#include <string>
class IFileLoader {
public:
    virtual std::string getFile(std::string& filePath) = 0;
    virtual bool saveFile(const std::string& data, const std::string& filePath) = 0;

    virtual ~IFileLoader() = default;
};
#endif /* I_FILE_LOADER_H */
