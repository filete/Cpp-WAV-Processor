#include "WavFile.hpp"
#include "IIRfilter.hpp"
#include "SynthWave.hpp"
#include "WavHeader.hpp"
#include <cstdint>

// Constructor
WavFile::WavFile(const std::string &filename) : mFileName(filename) {
  if (read())
    std::cout << "\x1b[34m" << mFileName << "\x1b[32m read successfuly!"
              << "\x1b[0m" << "\n";
}
WavFile::WavFile(const std::string &filename, const uint16_t bitsPerSample,
                 uint16_t channels, uint32_t sampleRate)
    : mFileName(filename), mHeader(bitsPerSample, channels, sampleRate) {
  std::cout << "\x1b[34m" << mFileName << "\x1b[32m created successfuly!"
            << "\x1b[0m" << "\n";
}

WavFile::~WavFile() {}

// File reader
bool WavFile::read() {
  std::ifstream audioFile;

  audioFile.open(mFilesPath + mFileName, std::ios::binary);

  if (mHeader.read(mFileName, audioFile)) {
    std::vector<uint8_t> buffer(mHeader.getDataSize());

    audioFile.read(reinterpret_cast<char *>(buffer.data()),
                   mHeader.getDataSize());

    int bytesPerSample = mHeader.getBitsPerSample() / 8;
    for (int i = 0; i < buffer.size(); i += bytesPerSample) {
      int16_t sample = *reinterpret_cast<int16_t *>(&buffer[i]);

      mAudioData.push_back(static_cast<float>(sample) /
                           (1 << (mHeader.getBitsPerSample() - 1)));
    }

    audioFile.close();
    return true;
  }

  std::cerr << "\x1b[31mError opening file: " << mFilesPath << "\x1b[0m"
            << "\n";
  audioFile.close();
  return false;
}

// Filw writer
bool WavFile::write(const std::string &fileName) {
  std::ofstream outputFile;
  outputFile.open(mFilesPath + fileName, std::ios::binary);

  if (outputFile) {
    mHeader.write(fileName, outputFile);
    for (const auto &sampleData : mAudioData) {
      int16_t sample = static_cast<int16_t>(
          sampleData * (1 << (mHeader.getBitsPerSample() - 1)));
      outputFile.write(reinterpret_cast<const char *>(&sample), sizeof(sample));
    }
    outputFile.close();
    std::cout << "File \x1b[34m" << fileName
              << "\x1b[32m written successfuly!\x1b[0m" << "\n";
    return true;
  }
  outputFile.close();
  std::cerr << "\x1b[31mError opening file: " << fileName << "\x1b[0m" << "\n";
  return false;
}

// Fileter processign
bool WavFile::applyFilter() {
  IIRfilter filter(*this);
  mAudioData = filter.applyFileFilter(*this);
  return true;
}

bool WavFile::applyFilter(uint16_t cutoff) {
  IIRfilter filter(*this);
  mAudioData = filter.applyFileFilter(*this, cutoff);
  return true;
}

void WavFile::synthAudio(const SynthWave::WaveType wave, const float duration,
                         const float frequency, const float amp) {
  SynthWave synth =
      SynthWave(mHeader.getBitsPerSample(), mHeader.getNumChannels(),
                mHeader.getSampleRate());

  mAudioData = synth.waveData(wave, duration, frequency, amp);

  const uint32_t bytesPerSample{mHeader.getBitsPerSample() / 8u};

  const uint32_t dataBytes =
      static_cast<uint32_t>(mAudioData.size()) * bytesPerSample;

  mHeader.setDataSize(dataBytes);
  mHeader.setFileSize();
  write(mFileName);
}

// Info logger
const void WavFile::printData(int size) {
  for (int i = 0; i < size; i++) {
    std::cout << "Value " << i << ":\t" << mAudioData[i] << "\n";
  }
}
