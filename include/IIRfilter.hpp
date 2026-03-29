#pragma once

#include "Constants.hpp"
#include "WavFile.hpp"
#include "WavHeader.hpp"
#include <cstdint>
#include <vector>

class IIRfilter {
public:
  IIRfilter(const WavFile &audioFile);
  ~IIRfilter();

  void setCutoff(const uint16_t frequency);
  float applySampleFilter(const float inputFrame);
  float applySampleFilter(const float inputFrame, const uint16_t cutoff);
  std::vector<float> applyFileFilter(const WavFile &audioFile);
  std::vector<float> applyFileFilter(const WavFile &audioFile, uint16_t cutoff);

private:
  uint32_t mSampleRate{};
  float mAlpha{};
  float mCutOff{1000.0f};
  float mPreviousSample{};

  void setAlpha();
};
