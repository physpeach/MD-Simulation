# Use the latest Ubuntu image
FROM ubuntu:latest

# apt update and upgrade
RUN apt update && apt upgrade -y && apt install -y \
    curl \
    wget \
    vim \
    git \
    build-essential \
    clang \
    clang-format \
    clang-tidy \
    cmake \
    ninja-build \
    gdb \
    libc6-dev \
    libc++-dev
# --------
# libc6-dev: C standard library development files for dev
# libc++-dev: C++ standard library development files for dev
# ---------

# Install Python for generating the compile_commands.json file
## Install dependencies
RUN apt install -y --no-install-recommends \
    dpkg-dev \
    gnupg \
    libbluetooth-dev \
    libbz2-dev \
    libc6-dev \
    libdb-dev \
    libffi-dev \
    libgdbm-dev \
    liblzma-dev \
    libncursesw5-dev \
    libreadline-dev \
    libsqlite3-dev \
    libssl-dev \
    xz-utils \
    zlib1g-dev

RUN curl https://pyenv.run | bash

# Set environment variables for pyenv
ENV PYENV_ROOT="/root/.pyenv"
ENV PATH="$PYENV_ROOT/bin:$PATH"

RUN pyenv install 3.13.2 && pyenv global 3.13.2
ENV PATH="$PYENV_ROOT/versions/3.13.2/bin:$PATH"
RUN python3 -m pip install compdb
