#pragma once
#include "WavHeader.h"
#include <vector>

class WavFile {
public:
  WavFile(const std::string &filename);
  ~WavFile();
  bool read();
  const WavHeader &getHeader() const;
  const std::vector<float> &getData() const;

private:
  std::string fileName;
  WavHeader header{};
  std::vector<float> audioData{};
};
