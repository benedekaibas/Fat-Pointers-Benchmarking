# Use an official Ubuntu as a parent image
FROM ubuntu:20.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    libomp-dev \
    git \
    cmake \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Install Checked C
RUN git clone https://github.com/microsoft/checkedc-clang.git /checkedc-clang \
    && cd /checkedc-clang \
    && git checkout checkedc-release_11.x \
    && mkdir build \
    && cd build \
    && cmake -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS=clang -G "Unix Makefiles" ../llvm \
    && make -j$(nproc) \
    && make install

# Set the working directory
WORKDIR /workspace

# Copy the current directory contents into the container at /workspace
COPY . /workspace

# Compile the Checked C code
RUN clang -fcheckedc-extension -Xpreprocessor -fopenmp -I/usr/local/include -L/usr/local/lib -lomp -o checked_c checked_c.c

# Run the executable
CMD ["./checked_c"]