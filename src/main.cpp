#include "WavHeader.h"
#include <iostream>

int main(void) {
  WavHeader *testWav = new WavHeader();
  std::cout << testWav->read("guitar.wav") << "\n";
  return 0;
}
