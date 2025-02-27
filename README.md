# Fat-Pointers-Benchmarking

The objective of this research is to implement both normal and fat pointers in the C language, Rust and analyze their benchmarking performance. By evaluating the execution speed of different implementations, we can assess whether sacrificing some performance is justifiable in exchange for enhanced security.

Microbenchmarking is employed to measure the execution time and performance of a small yet critical component of a real program. In this study, both the default (single-threaded) and OMP (Open Multi-Processing) benchmarking methods were utilized. OMP leverages multiple threads to accelerate execution by distributing computations across them. The default method serves as a baseline for comparison against OMP execution.

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

### Compile Rust

- cd into `src/src/src` folder where `main.rs` is located and run the following command:

`cargo build` and then `cargo run`

This will build the code and run it, so you will be able to see the benchmarking results.

### Checked C

The Dockerfile is already created, so just `cd` into the `src` folder and use the following commands:

- docker build -t checkedc-benchmark . (Build a docker image)

- docker run --rm checkedc-benchmark (start the checked c code)

If you want to start the Docker daemon manually then run the following command: `sudo systemctl start docker`

## Benchmark Result

![Benchmarking Result](src/visualization/picture/benchmarking_result.png)

## Are the Benchmarking codes safe?

I utilized the `Clang Static Analyzer` tool to verify that the benchmarking code is free of bugs. However, since this tool is designed specifically for C/C++ code, no equivalent safety check has been incorporated for the Rust benchmarking code in this research thus far.

### Here are the results

- Benchmarking in `C`

```text
benedekkaibas@Benedeks-MacBook-Pro src % scan-build clang -fopenmp -L/usr/local/opt/libomp/lib -I/usr/local/opt/libomp/include default_c.c -o default_c
scan-build: Using '/usr/local/Cellar/llvm/19.1.7_1/bin/clang-19' for static analysis
scan-build: Analysis run complete.
scan-build: Removing directory '/var/folders/g2/5kn8dryj619gk260gdvfrh1c0000gn/T/scan-build-2025-02-26-172131-7433-1' because it contains no reports.
scan-build: No bugs found.
```

- Benchmarking `Checked C`

```text
benedekkaibas@Benedeks-MacBook-Pro src % scan-build clang -fopenmp -L/usr/local/opt/libomp/lib -I/usr/local/opt/libomp/include checked_c.c -o checked_c
scan-build: Using '/usr/local/Cellar/llvm/19.1.7_1/bin/clang-19' for static analysis
scan-build: Analysis run complete.
scan-build: Removing directory '/var/folders/g2/5kn8dryj619gk260gdvfrh1c0000gn/T/scan-build-2025-02-26-172131-7433-1' because it contains no reports.
scan-build: No bugs found.
```

- Benchmarking `C++`

```text
benedekkaibas@Benedeks-MacBook-Pro src % scan-build clang -fopenmp -L/usr/local/opt/libomp/lib -I/usr/local/opt/libomp/include code.cpp -o default_cpp
scan-build: Using '/usr/local/Cellar/llvm/19.1.7_1/bin/clang-19' for static analysis
scan-build: Analysis run complete.
scan-build: Removing directory '/var/folders/g2/5kn8dryj619gk260gdvfrh1c0000gn/T/scan-build-2025-02-26-173024-7670-1' because it contains no reports.
scan-build: No bugs found.
```

- Benchmarking `C++ using Smart Pointers`

```text
benedekkaibas@Benedeks-MacBook-Pro src % scan-build clang++ -std=c++11 -stdlib=libc++ -fopenmp -L/usr/local/opt/libomp/lib -I/usr/local/opt/libomp/include smart.cpp -o smart
scan-build: Using '/usr/local/Cellar/llvm/19.1.7_1/bin/clang-19' for static analysis
scan-build: Analysis run complete.
scan-build: Removing directory '/var/folders/g2/5kn8dryj619gk260gdvfrh1c0000gn/T/scan-build-2025-02-26-173645-8397-1' because it contains no reports.
scan-build: No bugs found.
```

**NOTE**: You have to replace to commands to your actual path if you want to run the Static Analyzer!


## FAQ  

To successfully run the experiments, ensure that all necessary tools are installed:  

- **Checked C**: Download from the official repository [here](https://github.com/checkedc/checkedc).  
- **OpenMP**: Install via Homebrew by running:  
  ```sh
  brew install libomp
  ```

### Clang Static Analyzer  

- **[Clang Static Analyzer](https://clang-analyzer.llvm.org/)**: Download from the official website.

- **Programming Languages**: Obtain the latest versions from their respective official websites:  
  - **[C (GCC)](https://gcc.gnu.org/)**  
  - **[C++](https://isocpp.org/get-started)**  
  - **[Rust](https://www.rust-lang.org/)**