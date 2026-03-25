#include "IIRfilter.hpp"


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

void IIRfilter::setCutoff(const uint16_t frequency) { cutOff = frequency; }

float IIRfilter::applySampleFilter(const float inputSample) {
  previousSample = alpha * inputSample + (1 - alpha) * previousSample;
  return previousSample;
}

float IIRfilter::applySampleFilter(const float inputSample, const uint16_t cutoff) {
  setCutoff(cutoff);
  setAlpha();
  previousSample = alpha * inputSample + (1 - alpha) * previousSample;
  return previousSample;
}

std::vector<float> IIRfilter::applyFileFilter(const WavFile &audioFile) {
  std::vector<float> processedAudio = audioFile.getData();
  for (size_t i = 0; i < processedAudio.size(); ++i) {
    processedAudio[i] = applySampleFilter(processedAudio[i]);
  }
  //std::cout << "Filtered audio size: \x1b[33m" << processedAudio.size() << "\x1b[0m" << "\n";
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
  //std::cout << "Filtered audio size: \x1b[33m" << processedAudio.size() << "\x1b[0m" << "\n";
  return processedAudio;
}
