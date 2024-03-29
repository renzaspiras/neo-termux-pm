pkg-update="https://raw.githubusercontent.com/renzaspiras/arch-termux/main/pkg-upgrade.sh"
pkg="https://raw.githubusercontent.com/renzaspiras/arch-termux/main/package.sh"
# updates the package
curl -fsSL $pkg-update | sh

#installs the packages
curl -fsSL $pkg |sh

mkdir ~/apps; \
termux-setup-storage; \
proot-distro install archlinux; \
proot-distro login archlinux; #-- any bash commands;
