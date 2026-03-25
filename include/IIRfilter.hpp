#pragma once
#include "WavFile.hpp"
#include "WavHeader.hpp"
#include <cstdint>
#include <vector>

class IIRfilter {
public:
  IIRfilter(const WavFile &audioFile);
  ~IIRfilter();

  void setCutoff(uint16_t frequency);
  float applySampleFilter(float inputFrame);
  float applySampleFilter(float inputFrame, uint16_t cutoff);
  std::vector<float> applyFileFilter(const WavFile &audioFile);
  std::vector<float> applyFileFilter(const WavFile &audioFile, uint16_t cutoff);

private:
  const float PI = 3.14159265358979323846f;

  uint32_t sampleRate{};
  float alpha{};
  float cutOff{};
  float previousSample{};

  void setAlpha();
};
