# updates
# pkg upgrade
# pkg update
# pkg install root-repo
# pkg install x11-repo

# Languages
# pkg install python
pkg install clang
# pkg install golang
# pkg install cmake

# Utility
pkg install git
# pkg install neovim
pkg install neofetch
# pkg install wget
pkg install zsh

mv ~/hello/patch/cm-utils.c ~/cm.c
gcc ~/cm.c -o ~/cm
mkdir ~/bin/
mv ~/cm ~/bin/cm

# pkg install proot-distro