# Procesador de WAV en C++

procesador de ficheros .wav con c++ (en construcción).

##### Funcionalidades

- [x] Leer e interpretar la información de la cabecera de un wav.
- [x] Leer e interpretar la información de los datos de un wav.
- [ ] Procesar los datos del fichero aplicando un IIR(**R**espuesta de **I**mpulsos **I**nfinita) pasa-alto/pasa-bajo
- [ ] Escribir un fichero .wav con los datos procesados
- [ ] Añadir argumentos en línea de comandos.
- [ ] Visualización del FFT mediante ASCII (*opcional*).

##### Tecnologías usadas

- C++17
- CMake

##### Cómo compilarlo

```bash
mkdir build && cd build
cmake ..
cmake --build .
```
