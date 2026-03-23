#include "WavHeader.h"
#include <fstream>
#include <iostream>
#include <string>

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

    return 1;
  } else {
    std::cerr << "Error opening file. \n";
    return 0;
  }
}

void WavHeader::printState() {
  std::cout << "File Type: "
            << std::string(fileTypeBlocID.data(), fileTypeBlocID.size())
            << "\n";
  std::cout << "File Size: " << fileSize << "\n";
  std::cout << "File Format: "
            << std::string(fileFormatID.data(), fileFormatID.size()) << "\n";
  std::cout << "Format Bloc ID: "
            << std::string(formatBlocID.data(), formatBlocID.size()) << "\n";
  std::cout << "Bloc Size: " << blocSize << "\n";
  std::cout << "Audio Format: " << audioFormat << "\n";
  std::cout << "Num Channels: " << numChannels << "\n";
  std::cout << "Sample Rate: " << sampleRate << "\n";
  std::cout << "Byte Rate: " << byteRate << "\n";
  std::cout << "Byte Per Bloc: " << bytePerBloc << "\n";
  std::cout << "Bits Per Sample: " << bitsPerSample << "\n";
  std::cout << "Data Bloc ID: "
            << std::string(dataBlocId.data(), dataBlocId.size()) << "\n";
  std::cout << "Data Size: " << dataSize << "\n";
}
