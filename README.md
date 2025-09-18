# Fat-Pointers-Benchmarking

This research benchmarks raw and fat pointer implementations in C, Checked C, C++, and Rust, evaluating the trade-offs between performance and memory safety. Using microbenchmarks under both single-threaded and OpenMP parallel execution, the study measures runtime overhead, scaling behavior, and security implications. Results show that while fat pointers introduce overhead in sequential workloads, parallelism and careful metadata management can significantly reduce their cost, making them a viable approach for safer, performance-sensitive systems.

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

## Research Paper

Access to the research paper: file: [Research Paper](https://drive.google.com/file/d/1XLZnCL-AZSspktfX3Vj6o35muS4v48JS/view?usp=drive_link)
