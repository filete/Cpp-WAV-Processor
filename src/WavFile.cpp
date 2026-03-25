#include "WavFile.hpp"
#include "IIRfilter.hpp"
#include <cstdint>
#include <iterator>
#include <string>

WavFile::WavFile(const std::string &filename) : fileName(filename) {
  if (read())
    std::cout << "\x1b[34m" << fileName << "\x1b[32m read successfuly!" << "\x1b[0m" << "\n";
}

WavFile::~WavFile() {
  audioData.clear();
  header = {};
}
// Getetrs
const WavHeader &WavFile::getHeader() const { return header; }
const std::vector<float> &WavFile::getData() const { return audioData; }

// File reading
bool WavFile::read() {
  std::ifstream audioFile;

  audioFile.open(filesPath + fileName, std::ios::binary);

  if (header.read(fileName, audioFile)) {
    std::vector<uint8_t> buffer(header.getDataSize());

    audioFile.read(reinterpret_cast<char *>(buffer.data()),
                   header.getDataSize());

    int bytesPerSample = header.getBitsPerSample() / 8;
    for (int i = 0; i < buffer.size(); i += bytesPerSample) {
      int16_t sample = *reinterpret_cast<int16_t *>(&buffer[i]);

      audioData.push_back(static_cast<float>(sample) /
                          (1 << (header.getBitsPerSample() - 1)));
    }

    audioFile.close();
    return true;
  }

  std::cerr << "\x1b[31mError opening file: " << filesPath << "\x1b[0m" << "\n";
  audioFile.close();
  return false;
}

bool WavFile::write(const std::string &fileName) {
  std::ofstream outputFile;
  outputFile.open(filesPath + fileName , std::ios::binary);

  if (outputFile) {
    header.write(fileName, outputFile);
    for (const auto &sampleData : audioData) {
      int16_t sample = static_cast<int16_t>(
          sampleData * (1 << (header.getBitsPerSample() - 1)));
      outputFile.write(reinterpret_cast<const char *>(&sample), sizeof(sample));
    }
    outputFile.close();
    std::cout << "File \x1b[34m" << fileName << "\x1b[32m written successfuly!\x1b[0m" << "\n";
    return true;
  }
  outputFile.close();
  std::cerr << "\x1b[31mError opening file: " << fileName << "\x1b[0m" << "\n";
  return false;
}

bool WavFile::applyFilter() {
  IIRfilter filter(*this);
  audioData = filter.applyFileFilter(*this);
  return true;
}
bool WavFile::applyFilter(uint16_t cutoff) {
  IIRfilter filter(*this);
  audioData = filter.applyFileFilter(*this, cutoff);
  return true;
}

const void WavFile::printData(int size) {
  for (int i = 0; i < size; i++) {
    std::cout << "Value " << i << ":\t" << audioData[i] << "\n";
  }
}
