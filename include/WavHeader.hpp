#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <fstream>
#include <iostream>

class WavHeader {
public:
  WavHeader();
  ~WavHeader();
  bool read(const std::string &fileName, std::ifstream &audioFile);
  bool write(const std::string &fileName, std::ofstream &outputFile);
  void printState();
  uint32_t getDataSize() const { return dataSize; }
  uint32_t getFileSize() const { return fileSize; }
  uint16_t getNumChannels() const { return numChannels; }
  uint32_t getSampleRate() const { return sampleRate; }
  uint16_t getBitsPerSample() const { return bitsPerSample; }

private:
  // Master RIFF chunk
  std::array<char, 4> fileTypeBlocID{};
  uint32_t fileSize{};
  std::array<char, 4> fileFormatID{};
  // Chunk describing the data format
  std::array<char, 4> formatBlocID{};
  uint32_t blocSize{};
  uint16_t audioFormat{};
  uint16_t numChannels{};
  uint32_t sampleRate{};
  uint32_t byteRate{};
  uint16_t bytePerBloc{};
  uint16_t bitsPerSample{};
  // Chunk containing the sampled data
  std::array<char, 4> dataBlocId{};
  uint32_t dataSize{};
};
