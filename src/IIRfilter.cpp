#include "IIRfilter.hpp"
#include "WavFile.hpp"
#include "WavHeader.hpp"
#include <cstdint>
#include <vector>

IIRfilter::IIRfilter(const WavFile &audioFile) {
  sampleRate = audioFile.getHeader().getSampleRate();
  setAlpha();
}
IIRfilter::~IIRfilter() {}

void IIRfilter::setAlpha() {
  const float dt = (1.0f / sampleRate);
  const float rc = (1.0f / (2 * PI * cutOff));
  alpha = (dt / (rc + dt));
}

void IIRfilter::setCutoff(uint16_t frequency) { cutOff = frequency; }

float IIRfilter::applySampleFilter(float inputSample) {
  previousSample = alpha * inputSample + (1 - alpha) * previousSample;
  return previousSample;
}

float IIRfilter::applySampleFilter(float inputSample, uint16_t cutoff) {
  setCutoff(cutoff);
  setAlpha();
  previousSample = alpha * inputSample + (1 - alpha) * previousSample;
  return previousSample;
}

std::vector<float> IIRfilter::applyFileFilter(const WavFile &audioFile) {
  std::vector<float> processedAudio = audioFile.getData();
  for (const auto &sampleData : audioFile.getData()) {
    applySampleFilter(sampleData);
  }
  std::cout << "Filtered audio size: " << processedAudio.size() << "\n";
  return processedAudio;
}

std::vector<float> IIRfilter::applyFileFilter(const WavFile &audioFile,
                                              uint16_t cutoff) {
  setCutoff(cutoff);
  setAlpha();
  std::vector<float> processedAudio = audioFile.getData(); // copia
  for (size_t i = 0; i < processedAudio.size(); ++i) {
    processedAudio[i] = applySampleFilter(processedAudio[i]);
  }
  std::cout << "Filtered audio size: " << processedAudio.size() << "\n";
  return processedAudio;
}
