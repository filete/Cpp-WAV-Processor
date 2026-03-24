#include "main.h"

int main(void) {
  uint16_t cutoff{};

  std::cout << "Enter cutoff frequency: ";
  std::cin >> cutoff;

  WavFile testWav("guitar16b.wav");
  testWav.applyFilter(cutoff);
  testWav.write("output");

  return 0;
}
