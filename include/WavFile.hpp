#pragma once

#include "WavHeader.hpp"
#include <cstdint>
#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

class WavFile {
public:
  WavFile(const std::string &filename);
  ~WavFile();

  // File operations
  bool read();
  bool write(const std::string &fileName);

  bool applyFilter();
  bool applyFilter(uint16_t cutoff);

  // Getters, Setters and Info
  const WavHeader &getHeader() const;
  const std::vector<float> &getData() const;
  const std::string &getFilePath() const;
  void setFilePath(const std::string &path);
  const void printData(int size);

private:
  std::string fileName;
  WavHeader header{};
  std::vector<float> audioData{};
  std::string filesPath = "../samples/";
};
