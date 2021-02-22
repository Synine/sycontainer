# Sycontainer

This is a data-structure which can hold heterogenous data in a homogenous structure.

In cases where one needs to write data-structures where heterogenous data needs to be saved, one can use this data-structure to implement the heterogenity of the data-structure by using the abstractions that implement it, and focus on writing the data-structures more.

## Installation

Make sure to install [`GCC`](https://gcc.gnu.org/), [`Meson`](https://mesonbuild.com/) and [`Ninja`](https://ninja-build.org/) on your system **before starting**.

### Ubuntu and other Debian-based Distributions
```
sudo apt update && sudo apt install build-essential meson ninja -y
```
### Fedora and RHEL-based distributions
```bash
sudo dnf install "@C Development Tools and Libraries" meson ninja-build -y
```
### Arch-linux and derivaties
```
sudo pacman -S base-devel meson ninja
```

### Installing the `sycontainer` library (give permission when asked)
```
./install.sh
```
Make sure to **NOT** remove this directory, nor the generated `_build` directory after installation. This directory is required to uninstall library from your system.

## Uninstalling
**Make sure you DON'T remove the directory you used to install it.**
```bash
./uninstall.sh
```

## LICENSE

Copyright (c) 2020 Goutham Krishna K V

[MIT License](LICENSE)