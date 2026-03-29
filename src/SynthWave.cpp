#include "SynthWave.hpp"
#include <cstdlib>

SynthWave::SynthWave(uint32_t bitsPerSample, uint16_t channels,
                     uint32_t sampleRate)
    : mBlocSize(bitsPerSample), mChannels(channels), mSampleRate(sampleRate) {}

constexpr std::string_view SynthWave::waveType_toString(WaveType w) {
  switch (w) {
  case WaveType::SINE:
    return "Sine";
  case WaveType::SQUARE:
    return "Square";
  case WaveType::TRIANGLE:
    return "Triangle";
  case WaveType::SAWTOOTH:
    return "Sawtooth";
  }
}

std::vector<float> &SynthWave::waveData(const WaveType wave,
                                        const float duration_s,
                                        const float frequency,
                                        const float amp) {
  uint32_t totalSamples{static_cast<uint32_t>(mSampleRate * duration_s)};
  mAudioData.clear();
  mAudioData.reserve(totalSamples);

  const double phaseIncrease{static_cast<double>(frequency) /
                             static_cast<double>(mSampleRate)};
  double phase{0.0};
  for (uint32_t i{0}; i < totalSamples; i++) {
    float value{};
    switch (wave) {
    case (SynthWave::WaveType::SINE):
      value = static_cast<float>(std::sin(TWO_PI * phase)) * amp;
      break;
    case (SynthWave::WaveType::SQUARE):
      value = (phase < 0.5 ? 1.0f : -1.0f) * amp;
      break;
    case (SynthWave::WaveType::TRIANGLE):
      value = (static_cast<float>(4.0 * std::abs(phase - 0.5) - 1.0)) * amp;
      break;
    case (SynthWave::WaveType::SAWTOOTH):
      value = (static_cast<float>(2.0 * phase - 1.0)) * amp;
      break;
    }
    mAudioData.push_back(value);

    phase += phaseIncrease;
    if (phase >= 1.0)
      phase -= 1.0;
  }

  return mAudioData;
}
