# Sycontainer

C Library for a heterogenous data-structure container that can hold multiple types of data.

In cases where one needs to write data-structures where heterogenous data needs to be saved, one can use this data-structure to implement the heterogenity of the data-structure by using the abstractions that implement it, and focus on writing the data-structures more.

## Usage

Check out [USAGE](USAGE.md).

## Installation

### For Fedora Distributions (through COPR)

Fedora-specific builds exist, and are maintained in [Fedora COPR](https://copr.fedorainfracloud.org/coprs/gauthamkrishna9991/sycontainer/)

Builds exist for `x86_64` (64-bit x86) and `aarch64` (64-bit ARM).

To install it:
1.  Enable the Fedora COPR Repository:

    ```bash
    sudo dnf copr enable gauthamkrishna9991/sycontainer

    ```

2.  Install `sycontainer` using the following commmand

    ```bash
    sudo dnf install sycontainer -y
    ```

For Other Distributions

Make sure to install [`GCC`](https://gcc.gnu.org/), [`Meson`](https://mesonbuild.com/) and [`Ninja`](https://ninja-build.org/) on your system **before starting**.

### Ubuntu and other Debian-based Distributions
```
sudo apt update && sudo apt install build-essential pkg-config meson ninja -y
```
### Fedora and RHEL-based distributions (for building from source)
```bash
sudo dnf install "@C Development Tools and Libraries" meson ninja-build -y
```
### Arch-linux and derivaties
```
sudo pacman -S base-devel meson ninja
```

### Installing the `sycontainer` library

1.  Download the latest release from the releases tab from the right pane, and download the source file from a ZIP file you prefer.
2.  Extract the directory.
3.  Open a terminal window **in the directory** and run the following command.
    ```
    ./install.sh
    ```
Make sure to **NOT** remove this directory, nor the generated `_build` directory inside it after installation. This directory is required to uninstall library from your system.

If you want to keep your downloads directory clean, extract the archive to somewhere where it's more organized and repeat Step `3` (above) inside it.

## Uninstalling

**Make sure you DON'T remove the directory you used to install it.**

Open a terminal window in the installation directory and run the following command.
```bash
./uninstall.sh
```

## LICENSE

Copyright (c) 2020 Goutham Krishna K V

[MIT License](LICENSE)