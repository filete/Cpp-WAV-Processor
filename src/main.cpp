#include "main.hpp"
#include "CLI11.hpp"

int main(int argc, char* argv[]) {
    CLI::App app{"WAV file processor"};
    argv = app.ensure_utf8(argv);

    std::string inputFile, outputFile;
    uint16_t cutoff{};

    app.add_option("input", inputFile, "Input WAV file name") -> required();
    app.add_option("output", outputFile, "Output WAV file name") -> required();
    app.add_option("-c,--cutoff",cutoff, "Filter cutoff frequency in Hz");

    CLI11_PARSE(app, argc, argv);

  WavFile testWav(argv[1]);
  testWav.applyFilter(cutoff);
  testWav.write(argv[2]);

  return 0;
}
