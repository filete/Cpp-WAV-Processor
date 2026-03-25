([Español](https://github.com/filete/Cpp-WAV-Processor/blob/main/README_ES.md))

# C++ WAV Processor

c++ 16bit WAV PMC audio files processor (under construction).

### Functionalities

- [x] Read and interpret a .wav file header.
- [x] Read and interpret a .wav file data.
- [x] Process the data from the file applying an IIR(**I**nfinite **I**mpulse **R**esponse) lowpass/highpass filter.
- [x] Write a .wav output file with the processed data.
- [x] Add command line arguments.
- [ ] ASCII FFT visualisation (*optional*).

> **Only use 16bit WAV** — any other different format may couse undesired results.
> Be midnful with the playing volume of the output file. 

### Technologies used

- C++17
- CMake
- [CLI11](https://github.com/CLIUtils/CLI11) by [CLIUtils](https://github.com/CLIUtils)

### How to compile

```bash
mkdir build && cd build
cmake ..
cmake --build .
```
