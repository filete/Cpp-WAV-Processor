#pragma once

#include "SynthWave.hpp"
#include "WavHeader.hpp"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class WavFile {
public:
  WavFile(const std::string &filename);
  WavFile(const std::string &filename, const uint16_t bitsPerSample,
          uint16_t channels, uint32_t sampleRate);
  ~WavFile();

  // File operations
  bool read();
  bool write(const std::string &fileName);

  bool applyFilter();
  bool applyFilter(uint16_t cutoff);
  void synthAudio(const SynthWave::WaveType wave, const float duration,
                  const float frequency, const float amp);

  // Getters, Setters and Info
  const WavHeader &getHeader() const noexcept { return mHeader; }
  const std::vector<float> &getData() const noexcept { return mAudioData; }
  const std::string &getFilePath() const noexcept { return mFilesPath; }
  void setFilePath(const std::string &path) { mFilesPath = path; }

  const void printData(int size);

private:
  std::string mFileName;
  WavHeader mHeader;
  std::vector<float> mAudioData{};
  std::string mFilesPath = "../samples/";
};
