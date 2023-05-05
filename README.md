# PHL Collective "game"

This project is a simple game with both debug and release configurations.

## Dependencies

This project requires the following dependencies to be installed on your system:

- GCC (or another C++ compiler)
- SDL2 library
- SDL2_image library

## Building

To build the program, open a terminal or command prompt and navigate to the project directory. Then, run the following command:

```
mingw32-make all
```

This will build both the debug and release versions of the program.

To clean the build directory and remove all generated files, run the following command:

```
mingw32-make clean
```

## Running

After building the program, you can run it by executing the generated executable files. The debug version will be located at `debug.exe`, and the release version will be located at `release.exe`.
