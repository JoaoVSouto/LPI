# Diary project

## Compiling

This project is using [Cmake](https://cmake.org/) so make sure you have it installed on your system before taking the next steps.

1. On root folder run: `cmake -S . -Bbuild`. This will create a build folder that contains the Makefile and other CMake files.
2. `cd build`
3. `cmake --build .` or simply `make`

This will create the executable `diary` and `run_test` inside build directory.

## Running

Besides the main program you have the option to run the tests too.

### Program

On the root folder, run:

```
./build/diary
```

### Testing

On the root folder, run:

```
./build/run_test
```
