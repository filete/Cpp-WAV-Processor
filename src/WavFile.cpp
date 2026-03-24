#include "WavFile.h"

WavFile::WavFile(const std::string &filename) : fileName(filename) {
  if (read())
    std::cout << fileName << " read successfuly!" << "\n";
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

  std::string filesPath = "../samples/";
  std::ifstream audioFile;
  audioFile.open(filesPath.append(fileName), std::ios::binary);
  if (!header.read(fileName, audioFile)) {
    std::cerr << "file to open: " << filesPath << "\n";
    audioFile.close();
    return false;
  }

  std::vector<int8_t> buffer(header.getDataSize());
  audioFile.read(reinterpret_cast<char *>(buffer.data()), header.getDataSize());

  for (int i = 0; i < buffer.size(); i += 2) {
    int16_t sample = *reinterpret_cast<int16_t *>(&buffer[i]);
    if (i < 150)
      std::cout << "Sample " << i / 2 << ":\t" << sample << "\n";
    audioData.push_back(static_cast<float>(sample) /
                        (1 << (header.getBitsPerSample() - 1)));
  }

  audioFile.close();
  return true;
}

const void WavFile::printData(int size) {
  for (int i = 0; i < size; i++) {
    std::cout << "Value " << i << ":\t" << audioData[i] << "\n";
  }
}
