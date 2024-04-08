# Deletes the Default Messages on the startup of the TERMUX
cd ..
cd usr/etc
rm -rf motd

# Goes to the main home....
cd ~/
yes | termux-setup-storage

# File System
# Main directory for the filesystem
mkdir storage/shared/TERMUX/filesystem  

# Binaries directory for executable files
mkdir storage/shared/TERMUX/filesystem/bin  

# Directory for installed applications
mkdir storage/shared/TERMUX/filesystem/apps  

# Directory for scripts or applications to run on system startup
mkdir storage/shared/TERMUX/filesystem/autostart  

# Home directory for user-specific files and settings
mkdir storage/shared/TERMUX/filesystem/home

# Secondary hierarchy for read-only user data
mkdir storage/shared/TERMUX/filesystem/usr  

# Variable data directory for files that are expected to change during normal operation
mkdir storage/shared/TERMUX/filesystem/var

# Temporary directory for temporary files
mkdir storage/shared/TERMUX/filesystem/tmp

# Directory for system-wide configuration files
mkdir storage/shared/TERMUX/filesystem/etc  

# Directory for optional add-on software packages
mkdir storage/shared/TERMUX/filesystem/opt  

# Data directory for services provided by the system
mkdir storage/shared/TERMUX/filesystem/srv  

# Directory for bootloader files
mkdir storage/shared/TERMUX/filesystem/boot  


# Injecting My Own Config Achitecture
mv ~/hello/termux/lib/cm.py storage/shared/TERMUX/filesystem/etc/cm.py


# Installs the updates, and dependencies
yes | bash ~/hello/termux/package.sh

# gcc ~/hello/patch/cm-utils.c -o storage/shared/TERMUX/filesystem/bin/get

# on finish
touch storage/shared/TERMUX/TOKEN
echo "[PLEASE RE-OPEN THE APP]"
echo "[NO-ROOT FILESYSTEM IMPLEMENTED]"

mv ~/hello/termux/.bashrc ~/.bashrc
source ~/.bashrc