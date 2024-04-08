# Deletes the Default Messages on the startup of the TERMUX
cd ..
cd usr/etc
rm -rf motd

# Goes to the main home....
cd ~/
yes | termux-setup-storage

# File System
# Main directory for the filesystem
mkdir neo

# Binaries directory for executable files
mkdir neo/bin  

# Directory for installed applications
mkdir neo/apps  

# Directory for scripts or applications to run on system startup
mkdir neo/autostart  

# Home directory for user-specific files and settings
mkdir neo/home

# Secondary hierarchy for read-only user data
mkdir neo/usr  

# Variable data directory for files that are expected to change during normal operation
mkdir neo/var

# Temporary directory for temporary files
mkdir neo/tmp

# Directory for system-wide configuration files
mkdir neo/etc  

# Directory for optional add-on software packages
mkdir neo/opt  

# Data directory for services provided by the system
mkdir neo/srv  

# Directory for bootloader files
mkdir neo/boot  


# Injecting My Own Config Achitecture
mv ~/hello/termux/lib/cm.py neo/etc/cm.py


# Installs the updates, and dependencies
yes | bash ~/hello/termux/package.sh

# gcc ~/hello/patch/cm-utils.c -o neo/bin/get

# on finish
touch storage/shared/TERMUX/TOKEN
echo "[PLEASE RE-OPEN THE APP]"
echo "[NO-ROOT FILESYSTEM IMPLEMENTED]"

mv ~/hello/termux/.bashrc ~/.bashrc
source ~/.bashrc

rm -rf ~/hello

chmod 755 neo/bin/*

rm -rf hello
git clone https://github.com/renzaspiras/neo-termux-archlinux.git hello
cd hello
bash install.sh neotermux
rm -rf ~/hello
cd ~/