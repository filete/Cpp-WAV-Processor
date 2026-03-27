# Procesador de WAV en C++

> ([English](README.md))

Procesador de ficheros WAV PMC de 16bit con c++ (en construcción).

![GithubGif](https://github.com/user-attachments/assets/3cfd2c00-93cf-4bf5-b471-ba95049a65c1)

---

## Funcionalidades

- [x] Leer e interpretar la información de la cabecera de un wav.
- [x] Leer e interpretar la información de los datos de un wav.
- [x] Procesar los datos del fichero aplicando un IIR(**R**espuesta de **I**mpulsos **I**nfinita) pasa-bajo.
- [x] Escribir un fichero .wav con los datos procesados.
- [x] Añadir argumentos en línea de comandos.
- [ ] Visualización del FFT mediante ASCII (_opcional_).

> **Solo usar WAV de 16bit** — otro formato distinto puede dar resultados no esperados.
> Cuidado con el volumen de reproducción del fichero salida.

Probado en Linux y Windows 11.

## Como usarlo

### Uso

***

```sh
./wav-processor <ficheroEntrada.wav> <ficheroSalida.wav> [--cutoff <Hz>] [--filepath]
```

`<> = obligatorio   [] = opcional` .

***

**Ejemplo**:
*Usando los ficheros y carpeta de ejemplo.*
```sh
./wav-processor guitar16b.wav gitar600cu --cutoff 600 --filepath ../samples/
```

***

#### Argumentos

| Argumento | Explicación |
|----------|-------------|
| `-c`, `--cutoff` | Especifica la frecuencia de corte (Hz). |
| `-d`, `--file-dir` | Especifica el directorio de origen y destino de los archivos. |
| `-h`, `--help` | Imprime el mensaje de ayuda. |

## Tecnologías usadas

- C++17
- CMake
- [CLI11](https://github.com/CLIUtils/CLI11) por [CLIUtils](https://github.com/CLIUtils) ([LICENCIA](https://github.com/CLIUtils/CLI11/blob/main/LICENSE))

## Cómo compilarlo

*Usando CMake.*
```bash
mkdir build && cd build
cmake ..
cmake --build .
```
