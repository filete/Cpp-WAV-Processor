#pragma once

#include "Constants.hpp"
#include <cmath>
#include <cstdint>
#include <string_view>
#include <vector>

class SynthWave {
public:
  SynthWave(uint32_t bitsPerSample, uint16_t channels, uint32_t sampleRate);
  ~SynthWave() = default;

  enum class WaveType : uint8_t { SINE, SQUARE, TRIANGLE, SAWTOOTH };

  // Getters
  const uint32_t getBlocSize() const noexcept { return mBlocSize; }
  const uint16_t getChannels() const noexcept { return mChannels; }
  const uint32_t getSampleRate() const noexcept { return mSampleRate; }

  constexpr std::string_view waveType_toString(const WaveType w);

  std::vector<float> &waveData(const WaveType wave, const float duration_s,
                               const float frequency, const float amp);

private:
  uint32_t mBlocSize{};
  uint16_t mChannels{};
  uint32_t mSampleRate{};
  std::vector<float> mAudioData{};
};
