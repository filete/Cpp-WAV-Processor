#include "IIRfilter.hpp"

IIRfilter::IIRfilter(const WavFile &audioFile) {
  mSampleRate = audioFile.getHeader().getSampleRate();
  setAlpha();
}
IIRfilter::~IIRfilter() {}

void IIRfilter::setAlpha() {
  const float dt = (1.0f / mSampleRate);
  const float rc = (1.0f / (2 * PI * mCutOff));
  mAlpha = (dt / (rc + dt));
}

void IIRfilter::setCutoff(const uint16_t frequency) { mCutOff = frequency; }

float IIRfilter::applySampleFilter(const float inputSample,
                                   const float cutoff) {
  setCutoff(cutoff);
  setAlpha();
  mPreviousSample = mAlpha * inputSample + (1 - mAlpha) * mPreviousSample;
  return mPreviousSample;
}



std::vector<float> IIRfilter::applyFileFilter(const WavFile &audioFile,
                                              const float cutoff) {
  setCutoff(cutoff);
  setAlpha();
  std::vector<float> processedAudio = audioFile.getData(); // copia
  for (size_t i = 0; i < processedAudio.size(); ++i) {
    processedAudio[i] = applySampleFilter(processedAudio[i]);
  }
  // std::cout << "Filtered audio size: \x1b[33m" << processedAudio.size() <<
  // "\x1b[0m" << "\n";
  return processedAudio;
}
