# Fat-Pointers-Benchmarking

Doing Benchmarking Experiments Using Fat Pointers in C and Checked C

## How To Compile the files

### Default C

- cd to the path of your folder where you cloned the repository

`cd path/to/your/source/directory`

- Compile the c program file using GCC 14

`/usr/local/bin/gcc-14 gcc -O3 default_c.c -fopenmp -o default-c`

- Run the compiled program with the following command

`time ./default_c`

## Compile C++

- cd to the path of your folder where you cloned the repository

`cd path/to/your/source/directory`

- Compile the C++ program file using clang or gcc

`clang++ -O3 code.cpp -Xpreprocessor -fopenmp -I/usr/local/opt/libomp/include -L/usr/local/opt/libomp/lib -lomp -o code`

- Run the compiled program with the following command

`time ./code`

### Checked C
