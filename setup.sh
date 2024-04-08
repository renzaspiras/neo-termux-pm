# Deletes the Default Messages on the startup of the termux
cd ..
cd usr/etc
rm -rf motd

# Goes to the main home....
cd ~/
yes | termux-setup-storage

# File System
# Main directory for the filesystem
mkdir storage/shared/termux/filesystem  

# Binaries directory for executable files
mkdir storage/shared/termux/filesystem/bin  

# Directory for installed applications
mkdir storage/shared/termux/filesystem/apps  

# Directory for scripts or applications to run on system startup
mkdir storage/shared/termux/filesystem/autostart  

# Home directory for user-specific files and settings
mkdir storage/shared/termux/filesystem/home

# Secondary hierarchy for read-only user data
mkdir storage/shared/termux/filesystem/usr  

# Variable data directory for files that are expected to change during normal operation
mkdir storage/shared/termux/filesystem/var

# Temporary directory for temporary files
mkdir storage/shared/termux/filesystem/tmp

# Directory for system-wide configuration files
mkdir storage/shared/termux/filesystem/etc  

# Directory for optional add-on software packages
mkdir storage/shared/termux/filesystem/opt  

# Data directory for services provided by the system
mkdir storage/shared/termux/filesystem/srv  

# Directory for bootloader files
mkdir storage/shared/termux/filesystem/boot  

mv ~/hello/termux/.bashrc ~/.bashrc
# Installs the updates, and dependencies
#yes | bash ~/hello/termux/package.sh
#bash ~/hello/termux/config.sh
#cd ~/