# C++ WAV Processor

> Other languages: ([Español](README_ES.md))

Command-line tool for processing and synthesizing 16-bit PCM WAV audio files, written in C++17.

---

## Functionalities

- [ ] Read and interpret a .wav file header.
- [ ] Read and interpret a .wav file audio data.
- [ ] Process audio applying an IIR (Infinite Impulse Response) lowpass filter.
- [ ] Synthesize audio waveforms (sine, square, triangle, sawtooth).
- [ ] Write a .wav output file with processed or synthesized data.
- [ ] Full command-line interface with argument validation.
- [ ] ASCII FFT visualisation (optional).

> Only 16-bit WAV files are supported — other formats may produce unexpected results.
> Be mindful of the playback volume of the output file.

Tested on Linux and Windows 11.

## How to use

The program runs in two modes: **filter** and **synth**.

### Filter mode

Reads an existing WAV file, applies an IIR lowpass filter, and writes the result.

```sh
./wav-processor -m filter -i <input.wav> -o <output.wav> [options]
```

**Example:**

```sh
./wav-processor -m filter -i guitar16b.wav -o guitar_filtered.wav --cutoff 800 --file-dir ../samples/
```

### Synth mode

Generates a waveform and writes it to a WAV file.

```sh
./wav-processor -m synth -o <output.wav> [options]
```

**Example:**

```sh
./wav-processor -m synth -o sine440.wav -w 0 -f 440 -d 2.0 -a 0.8 --file-dir ../samples/
```

## Arguments

| Argument             | Mode   | Description                                                           |
| -------------------- | ------ | --------------------------------------------------------------------- |
| `-m`, `--mode`       | both   | Program mode: `filter` or `synth`. **Required.**                      |
| `-o`, `--output`     | both   | Output WAV file name. **Required.**                                   |
| `-i`, `--input-file` | filter | Input WAV file name.                                                  |
| `-c`, `--cutoff`     | filter | Filter cutoff frequency in Hz (0–20000).                              |
| `-w`, `--wave`       | synth  | Wave type: `0` sine, `1` square, `2` triangle, `3` sawtooth.          |
| `-f`, `--frequency`  | synth  | Oscillator frequency in Hz (0–20000). Default: `440`.                 |
| `-d`, `--duration`   | synth  | Duration of the output in seconds (0.2–30). Default: `1.0`.           |
| `-a`, `--amplitude`  | synth  | Amplitude of the output (0.0–1.0). Default: `0.85`.                   |
| `--file-dir`         | both   | Directory for input and output files, relative to the execution path. |
| `--header-info`      | both   | Print WAV header info after processing.                               |
| `-h`, `--help`       | both   | Print help message.                                                   |

---

## Technologies

- C++17
- CMake
- [CLI11](https://github.com/CLIUtils/CLI11) by [CLIUtils](https://github.com/CLIUtils) ([LICENSE](https://github.com/CLIUtils/CLI11/blob/main/LICENSE))

## How to compile

_Using CMake._

```bash
mkdir build && cd build
cmake ..
cmake --build .
```
