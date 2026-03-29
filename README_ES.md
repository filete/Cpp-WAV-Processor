# Procesador de WAV en C++

> Otros idiomas: [English](README.md)

Herramienta de línea de comandos para procesar y sintetizar ficheros de audio WAV PCM de 16 bits, escrita en C++17.

---

## Funcionalidades

- [x] Leer e interpretar la cabecera de un fichero .wav.
- [x] Leer e interpretar los datos de audio de un fichero .wav.
- [x] Procesar audio aplicando un filtro pasa-bajo IIR (**R**espuesta al **I**mpulso **I**nfinita).
- [x] Sintetizar formas de onda (seno, cuadrada, triangular, sierra).
- [x] Escribir un fichero .wav de salida con los datos procesados o sintetizados.
- [x] Interfaz de línea de comandos completa con validación de argumentos.
- [ ] Visualización del FFT mediante ASCII (_opcional_).

> **Solo se soportan ficheros WAV de 16 bits** — otros formatos pueden producir resultados inesperados.
> Presta atención al volumen de reproducción del fichero de salida.

Probado en Linux y Windows 11.

---

## Cómo usarlo

El programa funciona en dos modos: **filter** y **synth**.

### Modo filter

Lee un fichero WAV existente, aplica un filtro pasa-bajo IIR y escribe el resultado.

```sh
./wav-processor -m filter -i <entrada.wav> -o <salida.wav> [opciones]
```

**Ejemplo:**

```sh
./wav-processor -m filter -i guitar16b.wav -o guitar_filtrada.wav --cutoff 800 --file-dir ../samples/
```

### Modo synth

Genera una forma de onda y la escribe en un fichero WAV.

```sh
./wav-processor -m synth -o <salida.wav> [opciones]
```

**Ejemplo:**

```sh
./wav-processor -m synth -o seno440.wav -w 0 -f 440 -d 2.0 -a 0.8 --file-dir ../samples/
```

---

## Argumentos

| Argumento            | Modo   | Descripción                                                                          |
| -------------------- | ------ | ------------------------------------------------------------------------------------ |
| `-m`, `--mode`       | ambos  | Modo del programa: `filter` o `synth`. **Obligatorio.**                              |
| `-o`, `--output`     | ambos  | Nombre del fichero WAV de salida. **Obligatorio.**                                   |
| `-i`, `--input-file` | filter | Nombre del fichero WAV de entrada.                                                   |
| `-c`, `--cutoff`     | filter | Frecuencia de corte del filtro en Hz (0–20000).                                      |
| `-w`, `--wave`       | synth  | Tipo de onda: `0` seno, `1` cuadrada, `2` triangular, `3` sierra.                    |
| `-f`, `--frequency`  | synth  | Frecuencia del oscilador en Hz (0–20000). Por defecto: `440`.                        |
| `-d`, `--duration`   | synth  | Duración del fichero de salida en segundos (0.2–30). Por defecto: `1.0`.             |
| `-a`, `--amplitude`  | synth  | Amplitud de la señal (0.0–1.0). Por defecto: `0.85`.                                 |
| `--file-dir`         | ambos  | Directorio de los ficheros de entrada y salida, relativo al directorio de ejecución. |
| `--header-info`      | ambos  | Imprime la información de la cabecera WAV tras el procesado.                         |
| `-h`, `--help`       | ambos  | Imprime el mensaje de ayuda.                                                         |

---

## Tecnologías

- C++17
- CMake
- [CLI11](https://github.com/CLIUtils/CLI11) por [CLIUtils](https://github.com/CLIUtils) ([LICENCIA](https://github.com/CLIUtils/CLI11/blob/main/LICENSE))

## Cómo compilarlo

_Usando CMake._

```bash
mkdir build && cd build
cmake ..
cmake --build .
```
