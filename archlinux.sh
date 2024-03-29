proot-distro install archlinux

proot-distro login archlinux -- pacman -S neofetch
proot-distro login archlinux -- git clone https://aur.archlinux.org/paru.git && cd paru && makepkg -si