#!/usr/bin/bash
printf "\e[0;94mUninstalling sycontainer Library\e[0m\n";
sudo ninja uninstall -C _build/
printf "\e[0;92mLibrary successfully uninstalled\e[0m\n";