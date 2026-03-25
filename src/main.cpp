#include "main.hpp"

int main(int argc, char* argv[]) {
    CLI::App app{"WAV file processor"};
    argv = app.ensure_utf8(argv);

    std::string inputFile, outputFile, fileDirectory;
    uint16_t cutoff{};

    app.add_option("input", inputFile, "Input WAV file name") -> required();
    app.add_option("output", outputFile, "Output WAV file name") -> required();
    app.add_option("-c,--cutoff",cutoff, "Filter cutoff frequency in Hz");
    app.add_option("-d,--file-dir", fileDirectory, "Input file directory");

    CLI11_PARSE(app, argc, argv);


  WavFile testWav(inputFile);
  if(!fileDirectory.empty()){
      testWav.setFilePath(fileDirectory);
      std::cout << "File path set to: " << testWav.getFilePath() << std::endl;
  }
  if(cutoff){
      std::cout << "Applying filter with cutoff frequency: " << cutoff << " Hz" << std::endl;
      testWav.applyFilter(cutoff);
  }else{
      testWav.applyFilter();
  }
  testWav.write(outputFile);

  return 0;
}
