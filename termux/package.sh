# updates
# pkg upgrade
# pkg update
# pkg install root-repo
# pkg install x11-repo

# Languages
pkg install python
pkg install clang
# pkg install golang
# pkg install cmake

# Utility
pkg install git
# pkg install neovim
pkg install neofetch
pkg install wget
pkg install zsh

# Replacement of ls, but with icons
pkg install lsd

mv ~/hello/patch/cm-utils.c ~/cm.c
gcc ~/cm.c -o ~/cm
mkdir ~/bin/
mv ~/cm ~/bin/cm
rm cm.c

mv ~/hello/patch/apps.py ~/bin/apps.py
mv ~/hello/patch/git.sh ~/bin/git.sh

# pkg install proot-distro