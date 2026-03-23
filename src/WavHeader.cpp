#include "WavHeader.h"
#include <fstream>
#include <iostream>
#include <string>

WavHeader::WavHeader() {}
WavHeader::~WavHeader() {}
bool WavHeader::read(const std::string &fileName) {

  std::string filesPath = "./samples/";
  std::ifstream audioFile;
  audioFile.open(filesPath.append(fileName), std::ios::binary);

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
