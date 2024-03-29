# Craft Matrix
pkg upgrade

pkg install git
pkg install root-repo
pkg install x11-repo
pkg install neofetch

# installs programming languages
pkg install python
pkg install clang
mkdir ~/apps

termux-setup-storage

pkg install proot-distro

proot-distro install archlinux
clear
proot-distro login archlinux #-- any bash commands