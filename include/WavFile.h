#pragma once
#include "WavHeader.h"
#include <vector>

class WavFile {
public:
    WavFile(const std::string& filename);
    ~WavFile();
    bool read();
private:
    std::string fileName;
    WavHeader header{};
    std::vector<float> data{};
};
