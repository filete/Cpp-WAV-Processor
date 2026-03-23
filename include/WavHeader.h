#pragma once

#include <array>
#include <string>

class WavHeader {
public:
  WavHeader();
  ~WavHeader();
  bool read(const std::string &fileName);
  void printState();

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
