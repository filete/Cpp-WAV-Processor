#include "IIRfilter.h"
#include "WavFile.h"
#include "WavHeader.h"
#include <vector>

IIRfilter::IIRfilter(const WavHeader &fileInfo) {
  setAlpha(fileInfo.getSampleRate());
}
IIRfilter::~IIRfilter() {}

void IIRfilter::setAlpha(const uint32_t &sampleRate) {
  const float dt = (1.0f / sampleRate);
  const float rc = (1.0f / (2 * PI * cutOff));
  alpha = (dt / (rc + dt));
}

float IIRfilter::applySampleFilter(float inputSample) {
  previousSample = alpha * inputSample + (1 - alpha) * previousSample;
  return previousSample;
}

std::vector<float> IIRfilter::applyFileFilter(const WavFile &audioFile) {
  std::vector<float> processedAudio(audioFile.getHeader().getDataSize());
  for (auto &sampleInfo : audioFile.getData()) {
    processedAudio.push_back(applySampleFilter(sampleInfo));
  }
  return processedAudio;
}
