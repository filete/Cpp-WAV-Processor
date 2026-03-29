#pragma once

#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

class WavHeader {
public:
  WavHeader() = default;
  WavHeader(const uint16_t bitsPerSample, const uint16_t channels,
            const uint32_t sampleRate);
  ~WavHeader() = default;

  bool read(const std::string &fileName, std::ifstream &audioFile);
  bool write(const std::string &fileName, std::ofstream &outputFile);

  void printState() const;
  uint32_t getDataSize() const noexcept { return mDataSize; }
  uint32_t getFileSize() const noexcept { return mFileSize; }
  uint16_t getNumChannels() const noexcept { return mNumChannels; }
  uint32_t getSampleRate() const noexcept { return mSampleRate; }
  uint16_t getBitsPerSample() const noexcept { return mBitsPerSample; }

  void setDataSize(uint32_t dataSize);
  void setFileSize();

private:
  // Stetters
  void setFileTypeBlocID();
  void setFileFormatID();
  void setFormatBlocID();
  void setBlocSize();
  void setAudioFormat();
  void setNumChannels(uint16_t channels);
  void setSampleRate(uint32_t sampleRat);
  void setByteRate();
  void setBytePerBloc();
  void setBitsPerSample(uint16_t bitsPerSample);
  void setDataBlocId();

  // Master RIFF chunk
  std::array<char, 4> mFileTypeBlocID{};
  uint32_t mFileSize{};
  std::array<char, 4> mFileFormatID{};
  // Chunk describing the data format
  std::array<char, 4> mFormatBlocID{};
  uint32_t mBlocSize{};
  uint16_t mAudioFormat{};
  uint16_t mNumChannels{};
  uint32_t mSampleRate{};
  uint32_t mByteRate{};
  uint16_t mBytePerBloc{};
  uint16_t mBitsPerSample{};
  // Chunk containing the sampled data
  std::array<char, 4> mDataBlocId{};
  uint32_t mDataSize{};
};
