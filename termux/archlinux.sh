proot-distro install archlinux
clear
proot-distro login archlinux -- pacman -S neofetch --noconfirm
proot-distro login archlinux -- pacman -S zsh --noconfirm
proot-distro login archlinux -- pacman -S doas --noconfirm
proot-distro login archlinux -- pacman -S neovim --noconfirm
proot-distro login archlinux -- chsh -s /bin/zsh

meow=$(cat /termux/.zshrc)
proot-distro login archlinux -- echo "$meow" > ~/.zshrc