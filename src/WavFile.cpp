#include "WavFile.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

WavFile::WavFile(const std::string &filename) : fileName(filename) {
  if (read())
    std::cout << fileName << " read successfuly!" << "\n";
}

WavFile::~WavFile() {
  audioData.clear();
  header = {};
}

bool WavFile::read() {

  std::string filesPath = "../samples/";
  std::ifstream audioFile;
  audioFile.open(filesPath.append(fileName), std::ios::binary);
  if (!header.read(fileName, audioFile)) {
    std::cerr << "file to open: " << filesPath << "\n";
    audioFile.close();
    return false;
  }

  std::vector<uint8_t> buffer(header.getDataSize());
  audioFile.read(reinterpret_cast<char *>(buffer.data()), header.getDataSize());

  for (int i = 0; i < buffer.size(); i += 2) {
    int16_t sample = *reinterpret_cast<int16_t *>(&buffer[i]);
    audioData.push_back(static_cast<float>(sample) /
                        (1 << (header.getBitsPerSample() - 1)));
  }

  audioFile.close();
  return true;
}

const WavHeader &WavFile::getHeader() const { return header; }
const std::vector<float> &WavFile::getData() const { return audioData; }
