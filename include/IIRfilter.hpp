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
  float applySampleFilter(const float inputFrame, const float cutoff = 1000.f);
  std::vector<float> applyFileFilter(const WavFile &audioFile, const float cutoff = 1000.f);

private:
  uint32_t mSampleRate{};
  float mAlpha{};
  float mCutOff{1000.0f};
  float mPreviousSample{};

  void setAlpha();
};
