To build, run 
```bash
g++ [cpp_file_name] -o [output_file_name]
```

To run, since you're on Linux, do:
```bash
./[output_file_name]
```

# For RayLib
To build, run 
```bash
g++ [cpp_file_name] -o [output_file_name] $(pkg-config --cflags --libs raylib)
```

The output
```bash
-I/usr/local/include -L/usr/local/lib -lraylib
```
means:

- `-I/usr/local/include` — add `/usr/local/include` to the compiler include path (headers)
- `-L/usr/local/lib` — add `/usr/local/lib` to the linker search path (libraries)
- `-lraylib` — link against libraylib

Example compile command (bash, Linux):
```bash
gcc main.c $(pkg-config --cflags --libs raylib) -o main
```

You can also query flags separately:
```bash
pkg-config --cflags raylib
pkg-config --libs  raylib
```

This will include the raylib library into the build