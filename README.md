# C++ WAV Processor

> ([Español](README_ES.md))

c++ 16bit WAV PMC audio files processor (under construction).

![GithubGif](https://github.com/user-attachments/assets/3cfd2c00-93cf-4bf5-b471-ba95049a65c1)


---

## Functionalities

- [x] Read and interpret a .wav file header.
- [x] Read and interpret a .wav file data.
- [x] Process the data from the file applying an IIR(**I**nfinite **I**mpulse **R**esponse) lowpass filter.
- [x] Write a .wav output file with the processed data.
- [x] Add command line arguments.
- [ ] ASCII FFT visualisation (_optional_).

> **Only use 16bit WAV** — any other different format may cause undesired results.
> Be mindful with the playing volume of the output file.

Tested on Linux and Windows 11.

### How to use

#### Usage

***

```sh
./wav-processor <inputfile.wav> <outputfile.wav> [--cutoff <Hz>] [--filepath]
```

`<> = required   [] = optional` .

***

**Example**:
*Using the example audio files and folder.*
```sh
./wav-processor guitar16b.wav gitar600cu --cutoff 600 --filepath ../samples/
```

***

#### Arguments

| Argument | Explanation |
|----------|-------------|
| `-c`, `--cutoff` | Set the filter cutoff frequency (Hz). |
| `-d`, `--file-dir` | Select the directory for input and output files, relative to the program execution directory.|
| `-h`, `--help` | Print help message |

## Technologies used

- C++17
- CMake
- [CLI11](https://github.com/CLIUtils/CLI11) by [CLIUtils](https://github.com/CLIUtils) ([LICENSE](https://github.com/CLIUtils/CLI11/blob/main/LICENSE))

## How to compile

*Using CMake.*
```bash
mkdir build && cd build
cmake ..
cmake --build .
```
