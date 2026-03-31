#include "main.hpp"
#include "CLI11.hpp"

int main(int argc, char *argv[]) {
  CLI::App app{"WAV file processor"};
  argv = app.ensure_utf8(argv);

  std::string inputFile, outputFile, fileDirectory{"../samples/"}, mode;
  uint16_t waveTypeI{0};
  float cutoff{}, frequency{440.0f}, duration{1.0f}, amp{0.85};
  bool flag_headerInfo{false};

  app.add_option("-m,--mode", mode, "Program mode(filter | synth)")->required();
  app.add_option("-i,--input-file", inputFile, "Input WAV file name");
  app.add_option("-o,--output", outputFile, "Output WAV file name")->required();
  app.add_option("-c,--cutoff", cutoff, "Filter cutoff frequency in Hz")
      ->check(CLI::Range(0.f, 20000.f));
  app.add_option("-w,--wave", waveTypeI,
                 "Wave type to sinthesize (0 [sine] | 1 [square] | 2 "
                 "[triangle] | 3 [sawtooth])")
      ->check(CLI::Range(0, 3));
  app.add_option("-f,--frequency", frequency, "Wave frequency to synth in Hz")
      ->check(CLI::Range(0.0, 20000.0));
  app.add_option("-d,--duration", duration,
                 "Duration of the synthed output file")
      ->check(CLI::Range(0.2, 30.0));
  app.add_option("-a,--amplitude", amp, "Amplitude of the synthed output file")
      ->check(CLI::Range(0.0, 1.0));
  app.add_option("--file-dir", fileDirectory, "Input file directory");
  app.add_flag("--header-info", flag_headerInfo, "Flag to print file info.");

  CLI11_PARSE(app, argc, argv);

  if (mode == "filter") {
    WavFile testWav(inputFile);
    if (!fileDirectory.empty()) {
      testWav.setFilePath(fileDirectory);
      std::cout << "File path set to: " << testWav.getFilePath() << std::endl;
    }
    if (cutoff) {
      std::cout << "Applying filter with cutoff frequency: " << cutoff << " Hz"
                << std::endl;
      testWav.applyFilter(cutoff);
    } else {
      testWav.applyFilter();
    }
    testWav.write(outputFile);

    if (flag_headerInfo)
      testWav.getHeader().printState();
  } else {
    WavFile synthWav(outputFile, 16, 1, 44100);
    if (!fileDirectory.empty()) {
      synthWav.setFilePath(fileDirectory);
      std::cout << "File path set to: " << synthWav.getFilePath() << std::endl;
    }
    synthWav.synthAudio(static_cast<SynthWave::WaveType>(waveTypeI), duration,
                        frequency, amp);
    if (flag_headerInfo)
      synthWav.getHeader().printState();
  }
  return 0;
}
