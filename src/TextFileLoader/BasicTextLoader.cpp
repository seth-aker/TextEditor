#include "BasicTextLoader.h"
#include <iostream>
#include <fstream>
#include <string>

BasicTextLoader::BasicTextLoader() {};

std::string BasicTextLoader::getFile(std::string& filePath) {
    std::ifstream io;
    io.open(filePath);
    if (!io.is_open()) {
        std::cerr << "Failed to open file!";
        return NULL;
    }
    char c;
    std::string fileData{};
    while (io.get(c)) {
        fileData.append(&c);
    }
    io.close();
    return fileData;
}

bool BasicTextLoader::saveFile(const std::string& data, const std::string& filePath) {
    std::ofstream io{ filePath };
    io << data.c_str();
    if (io.bad()) {
        std::cerr << "An error occurred while writing to the file!";
        io.close();
        return false;
    }
    io.close();
    return true;
}
