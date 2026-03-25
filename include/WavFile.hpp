#pragma once
#include "WavHeader.hpp"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

class WavFile {
public:
  WavFile(const std::string &filename);
  ~WavFile();

  bool read();
  bool write(const std::string &fileName);

  bool applyFilter();
  bool applyFilter(uint16_t cutoff);

  const void printData(int size);
  const WavHeader &getHeader() const;
  const std::vector<float> &getData() const;

private:
  std::string fileName;
  WavHeader header{};
  std::vector<float> audioData{};
  std::string filesPath = "../samples/";
};
