# Procesador de WAV en C++

Procesador de ficheros WAV PMC de 16bit con c++ (en construcción).

([English](https://github.com/filete/Cpp-WAV-Processor/blob/main/README.md))

---

## Funcionalidades

- [x] Leer e interpretar la información de la cabecera de un wav.
- [x] Leer e interpretar la información de los datos de un wav.
- [x] Procesar los datos del fichero aplicando un IIR(**R**espuesta de **I**mpulsos **I**nfinita) pasa-alto/pasa-bajo
- [x] Escribir un fichero .wav con los datos procesados
- [x] Añadir argumentos en línea de comandos.
- [ ] Visualización del FFT mediante ASCII (_opcional_).

> **Solo usar WAV de 16bit** — otro formato distinto puede dar resultados no esperados.
> Cuidado con el volumen de reproducción del fichero salida.

Probado en Linux y Windows 11.

## Tecnologías usadas

- C++17
- CMake
- [CLI11](https://github.com/CLIUtils/CLI11) por [CLIUtils](https://github.com/CLIUtils) ([LICENCIA](https://github.com/CLIUtils/CLI11/blob/main/LICENSE))

## Cómo compilarlo

```bash
mkdir build && cd build
cmake ..
cmake --build .
```
