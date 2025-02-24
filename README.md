# Fat-Pointers-Benchmarking

The goal of this research is to create normal and fat pointers in the C languages and show the benchmarking difference. By measuring the pace of the different implementations, we can decide if it's reasonable to give up some performance, pace, but get more secureness. By doing microbenchmarking we can measure the time and/or performance of a small building block of a real program. I used default (single thread) and OMP (Open Multiprocessing) benchmarking methods in the research. OMP utilizes multiple threads to speed up the execution by that computations are performed using multiple threads. I used default method as a baseline result to compare OMP execution.


## How To Compile the files

### Default C

- cd to the path of your folder where you cloned the repository

`cd path/to/your/source/directory`

- Compile the c program file using GCC 14

`/usr/local/bin/gcc-14 gcc -O3 default_c.c -fopenmp -o default-c`

- Run the compiled program with the following command

`time ./default_c`

### Compile C++

- cd to the path of your folder where you cloned the repository

`cd path/to/your/source/directory`

- Compile the C++ program file using clang or gcc

`clang++ -O3 code.cpp -Xpreprocessor -fopenmp -I/usr/local/opt/libomp/include -L/usr/local/opt/libomp/lib -lomp -o code`

- Run the compiled program with the following command

`time ./code`

Use the same command for compiling `code.cpp` and `smart.cpp` program. For comparison it is important to use the same compiler.

### Checked C

The Dockerfile is already created, so just `cd` into the `src` folder and use the following commands:

- docker build -t checkedc-benchmark . (Build a docker image)

- docker run --rm checkedc-benchmark (start the checked c code)

If you want to start the Docker daemon manually then run the following command: `sudo systemctl start docker`
