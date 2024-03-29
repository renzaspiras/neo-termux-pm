pkg-update=https://raw.githubusercontent.com/renzaspiras/arch-termux/main/pkg-upgrade.sh
pkg=https://raw.githubusercontent.com/renzaspiras/arch-termux/main/package.sh
clear

# updates the package
curl -fsSL $pkg-update | sh

#installs the packages
curl -fsSL $pkg |sh