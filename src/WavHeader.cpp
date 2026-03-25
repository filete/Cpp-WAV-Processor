#include "WavHeader.hpp"

WavHeader::WavHeader() {}
WavHeader::~WavHeader() {}
bool WavHeader::read(const std::string &fileName, std::ifstream &audioFile) {

  if (audioFile) {
    audioFile.read(fileTypeBlocID.data(), sizeof(fileTypeBlocID));
    audioFile.read(reinterpret_cast<char *>(&fileSize), sizeof(fileSize));
    audioFile.read(fileFormatID.data(), sizeof(fileFormatID));

    audioFile.read(formatBlocID.data(), sizeof(formatBlocID));
    audioFile.read(reinterpret_cast<char *>(&blocSize), sizeof(blocSize));
    audioFile.read(reinterpret_cast<char *>(&audioFormat), sizeof(audioFormat));
    audioFile.read(reinterpret_cast<char *>(&numChannels), sizeof(numChannels));
    audioFile.read(reinterpret_cast<char *>(&sampleRate), sizeof(sampleRate));
    audioFile.read(reinterpret_cast<char *>(&byteRate), sizeof(byteRate));
    audioFile.read(reinterpret_cast<char *>(&bytePerBloc), sizeof(bytePerBloc));
    audioFile.read(reinterpret_cast<char *>(&bitsPerSample),
                   sizeof(bitsPerSample));

    audioFile.read(dataBlocId.data(), sizeof(fileTypeBlocID));
    audioFile.read(reinterpret_cast<char *>(&dataSize), sizeof(dataSize));

    return true;
  }
  std::cerr << "\x1b[31mError opening file: " << fileName << "\x1b[0m"
  << "\n";
  return false;
}

bool WavHeader::write(const std::string &fileName, std::ofstream &outputFile) {
  if (outputFile) {
    outputFile.write(fileTypeBlocID.data(), sizeof(fileTypeBlocID));
    outputFile.write(reinterpret_cast<char *>(&fileSize), sizeof(fileSize));
    outputFile.write(fileFormatID.data(), sizeof(fileFormatID));
    outputFile.write(formatBlocID.data(), sizeof(formatBlocID));
    outputFile.write(reinterpret_cast<char *>(&blocSize), sizeof(blocSize));
    outputFile.write(reinterpret_cast<char *>(&audioFormat),
                     sizeof(audioFormat));
    outputFile.write(reinterpret_cast<char *>(&numChannels),
                     sizeof(numChannels));
    outputFile.write(reinterpret_cast<char *>(&sampleRate), sizeof(sampleRate));
    outputFile.write(reinterpret_cast<char *>(&byteRate), sizeof(byteRate));
    outputFile.write(reinterpret_cast<char *>(&bytePerBloc),
                     sizeof(bytePerBloc));
    outputFile.write(reinterpret_cast<char *>(&bitsPerSample),
                     sizeof(bitsPerSample));
    outputFile.write(dataBlocId.data(), sizeof(dataBlocId));
    outputFile.write(reinterpret_cast<char *>(&dataSize), sizeof(dataSize));
    //std::cout << "File header written: \x1b[34m" << fileName << "\x1b[0m" << "\n";
    //printState();
    return true;
  }
  std::cerr << "\x1b[31mError opening file: " << fileName << "\x1b[0m"
  << "\n";
  return false;
}

void WavHeader::printState() {
  std::cout << "File Type: \x1b[33m"
            << std::string(fileTypeBlocID.data(), fileTypeBlocID.size())
            << "\x1b[0m" << "\n";
  std::cout << "File Size: \x1b[33m" << fileSize << "\x1b[0m" << "\n";
  std::cout << "File Format: \x1b[33m"
            << std::string(fileFormatID.data(), fileFormatID.size())
            << "\x1b[0m" << "\n";
  std::cout << "Format Bloc ID: \x1b[33m"
            << std::string(formatBlocID.data(), formatBlocID.size())
            << "\x1b[0m" << "\n";
  std::cout << "Bloc Size: \x1b[33m" << blocSize << "\x1b[0m" << "\n";
  std::cout << "Audio Format: \x1b[33m" << audioFormat << "\x1b[0m" << "\n";
  std::cout << "Num Channels: \x1b[33m" << numChannels << "\x1b[0m" << "\n";
  std::cout << "Sample Rate: \x1b[33m" << sampleRate << "\x1b[0m" << "\n";
  std::cout << "Byte Rate: \x1b[33m" << byteRate << "\x1b[0m" << "\n";
  std::cout << "Byte Per Bloc: \x1b[33m" << bytePerBloc << "\x1b[0m" << "\n";
  std::cout << "Bits Per Sample: \x1b[33m" << bitsPerSample << "\x1b[0m" << "\n";
  std::cout << "Data Bloc ID: \x1b[33m"
            << std::string(dataBlocId.data(), dataBlocId.size())
            << "\x1b[0m" << "\n";
  std::cout << "Data Size: \x1b[33m" << dataSize << "\x1b[0m" << "\n";
}
