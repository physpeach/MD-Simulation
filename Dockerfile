# Use the latest Ubuntu image
FROM ubuntu:latest

# apt update and upgrade
RUN apt update && apt upgrade -y && apt install -y \
    sudo \
    wget \
    vim \
    git \
# for c++
    build-essential \
    clang \
    clangd \
    clang-format \
    clang-tidy \
    cmake \
    ninja-build \
    gdb \
    libc6-dev \
    libc++-dev \
# for vcpkg
    curl \
    zip \
    unzip \
    pkg-config \
    tar
# --------
# libc6-dev: C standard library development files for dev
# libc++-dev: C++ standard library development files for dev
# pkg-config: manage compile and link flags for libraries
# ---------

RUN echo "ubuntu ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
