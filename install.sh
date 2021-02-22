#!/usr/bin/sh
# Install script for sycontainer
printf "\e[0;94mSetting up build-directories...\e[0m\n";
meson setup _build -Dbuildtype=release
# Build the project
printf "\e[0;94mBuilding the library...\e[0m\n";
meson compile -C _build/
# Install the script to your system
printf "\e[0;94mInstalling...\e[0m\n";
sudo ninja install -C _build/
printf "\e[0;92mLibrary Successfully Installed\e[0m\n";