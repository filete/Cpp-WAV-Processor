#pragma once
#include "WavFile.hpp"
#include "WavHeader.hpp"
#include <cstdint>
#include <vector>

static constexpr float PI = 3.14159265358979323846f;

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

  uint32_t sampleRate{};
  float alpha{};
  float cutOff{1000.0f};
  float previousSample{};

  void setAlpha();
};
