# Craft Matrix

yes | pkg upgrade

yes | pkg install git
yes | pkg install root-repo
yes | pkg install x11-repo
yes | pkg install neofetch
yes | pkg install proot-distro
yes | pkg install tmux

# installs programming languages
pkg install python
pkg install clang
mkdir ~/apps

termux-setup-storage

proot-distro install archlinux

proot-distro login archlinux #-- any bash commands