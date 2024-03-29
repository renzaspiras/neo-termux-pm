pkg-update="https://raw.githubusercontent.com/renzaspiras/arch-termux/main/pkg-upgrade.sh"

# updates the package
curl -fsSL $pkg-update | sh

mkdir ~/apps; \
termux-setup-storage; \
proot-distro install archlinux; \
proot-distro login archlinux; #-- any bash commands;
