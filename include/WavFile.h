#pragma once
#include "WavHeader.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

class WavFile {
public:
  WavFile(const std::string &filename);
  ~WavFile();
  bool read();
  const WavHeader &getHeader() const;
  const std::vector<float> &getData() const;
  const void printData(int size);

private:
  std::string fileName;
  WavHeader header{};
  std::vector<float> audioData{};
};
