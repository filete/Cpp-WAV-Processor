#include "WavHeader.hpp"
#include <cstdint>
#include <string>

// Synthesised constructor
WavHeader::WavHeader(const uint16_t bitsPerSample, const uint16_t channels,
                     const uint32_t sampleRate)
    : mBitsPerSample(bitsPerSample), mNumChannels(channels),
      mSampleRate(sampleRate) {
  setFileTypeBlocID();
  setFileFormatID();
  setFormatBlocID();
  setBlocSize();
  setAudioFormat();
  setByteRate();
  setBytePerBloc();
  setDataBlocId();
  // later setFileSize & setDataSize;
}

// Wav header data parser
bool WavHeader::read(const std::string &fileName, std::ifstream &audioFile) {

  if (audioFile) {
    audioFile.read(mFileTypeBlocID.data(), sizeof(mFileTypeBlocID));
    audioFile.read(reinterpret_cast<char *>(&mFileSize), sizeof(mFileSize));
    audioFile.read(mFileFormatID.data(), sizeof(mFileFormatID));

    audioFile.read(mFormatBlocID.data(), sizeof(mFormatBlocID));
    audioFile.read(reinterpret_cast<char *>(&mBlocSize), sizeof(mBlocSize));
    audioFile.read(reinterpret_cast<char *>(&mAudioFormat),
                   sizeof(mAudioFormat));
    audioFile.read(reinterpret_cast<char *>(&mNumChannels),
                   sizeof(mNumChannels));
    audioFile.read(reinterpret_cast<char *>(&mSampleRate), sizeof(mSampleRate));
    audioFile.read(reinterpret_cast<char *>(&mByteRate), sizeof(mByteRate));
    audioFile.read(reinterpret_cast<char *>(&mBytePerBloc),
                   sizeof(mBytePerBloc));
    audioFile.read(reinterpret_cast<char *>(&mBitsPerSample),
                   sizeof(mBitsPerSample));

    audioFile.read(mDataBlocId.data(), sizeof(mDataBlocId));
    audioFile.read(reinterpret_cast<char *>(&mDataSize), sizeof(mDataSize));

    return true;
  }
  std::cerr << "\x1b[31mError opening file: " << fileName << "\x1b[0m"
            << "\n";
  return false;
}

// Wav header writer
bool WavHeader::write(const std::string &fileName, std::ofstream &outputFile) {
  if (outputFile) {
    outputFile.write(mFileTypeBlocID.data(), sizeof(mFileTypeBlocID));
    outputFile.write(reinterpret_cast<char *>(&mFileSize), sizeof(mFileSize));
    outputFile.write(mFileFormatID.data(), sizeof(mFileFormatID));
    outputFile.write(mFormatBlocID.data(), sizeof(mFormatBlocID));
    outputFile.write(reinterpret_cast<char *>(&mBlocSize), sizeof(mBlocSize));
    outputFile.write(reinterpret_cast<char *>(&mAudioFormat),
                     sizeof(mAudioFormat));
    outputFile.write(reinterpret_cast<char *>(&mNumChannels),
                     sizeof(mNumChannels));
    outputFile.write(reinterpret_cast<char *>(&mSampleRate),
                     sizeof(mSampleRate));
    outputFile.write(reinterpret_cast<char *>(&mByteRate), sizeof(mByteRate));
    outputFile.write(reinterpret_cast<char *>(&mBytePerBloc),
                     sizeof(mBytePerBloc));
    outputFile.write(reinterpret_cast<char *>(&mBitsPerSample),
                     sizeof(mBitsPerSample));
    outputFile.write(mDataBlocId.data(), sizeof(mDataBlocId));
    outputFile.write(reinterpret_cast<char *>(&mDataSize), sizeof(mDataSize));
    // std::cout << "File header written: \x1b[34m" << fileName << "\x1b[0m" <<
    // "\n"; printState();
    return true;
  }
  std::cerr << "\x1b[31mError opening file: " << fileName << "\x1b[0m"
            << "\n";
  return false;
}

// Info logger
void WavHeader::printState() const {
  std::cout << "File Type: \x1b[33m"
            << std::string(mFileTypeBlocID.data(), mFileTypeBlocID.size())
            << "\x1b[0m" << "\n";
  std::cout << "File Size: \x1b[33m" << mFileSize << "\x1b[0m" << "\n";
  std::cout << "File Format: \x1b[33m"
            << std::string(mFileFormatID.data(), mFileFormatID.size())
            << "\x1b[0m" << "\n";
  std::cout << "Format Bloc ID: \x1b[33m"
            << std::string(mFormatBlocID.data(), mFormatBlocID.size())
            << "\x1b[0m" << "\n";
  std::cout << "Bloc Size: \x1b[33m" << mBlocSize << "\x1b[0m" << "\n";
  std::cout << "Audio Format: \x1b[33m" << mAudioFormat << "\x1b[0m" << "\n";
  std::cout << "Num Channels: \x1b[33m" << mNumChannels << "\x1b[0m" << "\n";
  std::cout << "Sample Rate: \x1b[33m" << mSampleRate << "\x1b[0m" << "\n";
  std::cout << "Byte Rate: \x1b[33m" << mByteRate << "\x1b[0m" << "\n";
  std::cout << "Byte Per Bloc: \x1b[33m" << mBytePerBloc << "\x1b[0m" << "\n";
  std::cout << "Bits Per Sample: \x1b[33m" << mBitsPerSample << "\x1b[0m"
            << "\n";
  std::cout << "Data Bloc ID: \x1b[33m"
            << std::string(mDataBlocId.data(), mDataBlocId.size()) << "\x1b[0m"
            << "\n";
  std::cout << "Data Size: \x1b[33m" << mDataSize << "\x1b[0m" << "\n";
}

void WavHeader::setFileTypeBlocID() {
  mFileTypeBlocID[0] = 'R';
  mFileTypeBlocID[1] = 'I';
  mFileTypeBlocID[2] = 'F';
  mFileTypeBlocID[3] = 'F';
}
void WavHeader::setFileSize() { mFileSize = 36 + mDataSize; }
void WavHeader::setFileFormatID() {
  mFileFormatID[0] = 'W';
  mFileFormatID[1] = 'A';
  mFileFormatID[2] = 'V';
  mFileFormatID[3] = 'E';
}
void WavHeader::setFormatBlocID() {
  mFormatBlocID[0] = 'f';
  mFormatBlocID[1] = 'm';
  mFormatBlocID[2] = 't';
  mFormatBlocID[3] = ' ';
}
void WavHeader::setBlocSize() { mBlocSize = 16; }
void WavHeader::setAudioFormat() { mAudioFormat = 1; }
void WavHeader::setNumChannels(uint16_t channels) { mNumChannels = channels; }
void WavHeader::setSampleRate(uint32_t sampleRate) { mSampleRate = sampleRate; }
void WavHeader::setByteRate() {
  mByteRate = mSampleRate * mBitsPerSample * mNumChannels / 8;
}
void WavHeader::setBytePerBloc() {
  mBytePerBloc = mBitsPerSample * mNumChannels / 8;
}
void WavHeader::setBitsPerSample(uint16_t bitsPerSample) {
  mBitsPerSample = bitsPerSample;
}
void WavHeader::setDataBlocId() {
  mDataBlocId[0] = 'd';
  mDataBlocId[1] = 'a';
  mDataBlocId[2] = 't';
  mDataBlocId[3] = 'a';
}
void WavHeader::setDataSize(uint32_t dataSize) { mDataSize = dataSize; }
