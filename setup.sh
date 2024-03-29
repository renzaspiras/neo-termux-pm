pkg upgrade; \
pkg install git; \
pkg install root-repo; \
pkg install x11-repo; \
pkg install neofetch; \
pkg install proot-distro; \
pkg install tmux; \
pkg install python; \
pkg install clang; \
mkdir ~/apps; \
termux-setup-storage; \
proot-distro install archlinux; \
proot-distro login archlinux; #-- any bash commands;
