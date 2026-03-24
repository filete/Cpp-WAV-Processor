#pragma once
#include "WavFile.h"
#include "WavHeader.h"
#include <cstdint>
#include <vector>

class IIRfilter {
public:
  IIRfilter(const WavHeader &fileInfo);
  ~IIRfilter();

  float setCutoff(uint16_t frequency);
  float applySampleFilter(float inputFrame);
  std::vector<float> applyFileFilter(const WavFile &audioFile);

private:
  const float PI = 3.14159265358979323846f;

  float previousSample{};
  float alpha{};
  float cutOff{};

  void setAlpha(const uint32_t &sampleRate);
};
