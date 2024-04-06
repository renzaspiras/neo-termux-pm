# Not needed anymore

proot-distro install archlinux
clear

# Updates and installs the 
proot-distro login archlinux -- pacman -Syu --noconfirm
proot-distro login archlinux -- pacman -S sudo --noconfirm
proot-distro login archlinux -- pacman -S zsh --noconfirm

# Applying .zshrc themes --> it is based on the default zsh on kali linux, with slight modification of mine...
proot-distro login archlinux -- wget https://raw.githubusercontent.com/renzaspiras/arch-termux/main/termux/.zshrc ~/.zshrc

proot-distro login archlinux -- wget https://raw.githubusercontent.com/renzaspiras/arch-termux/main/lang/.box.sh

proot-distro login archlinux -- chsh -s /bin/zsh