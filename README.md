([Español](https://github.com/filete/Cpp-WAV-Processor/blob/main/README_ES.md))
# C++ WAV Processor

c++ .wav audio files processor (under construction).

### Functionalities

- [x] Read and interpret a .wav file header.
- [x] Read and interpret a .wav file data.
- [ ] Process the data from the file applying an IIR lowpass/highpass filter.
- [ ] Write a .wav output file with the processed data.
- [ ] Add command line arguments.
- [ ] ASCII FFT visualisation (*optional*).

### Technologies used

- C++17
- CMake

### How to compile

```bash
mkdir build && cd build
cmake ..
cmake --build .
```
