# Deletes the Default Messages on the startup of the termux
cd ..
cd usr/etc
rm -rf motd

# Goes to the main home....
cd ~/

# Installs the updates, and dependencies
yes | bash ~/hello/termux/package.sh

# Enables 
yes | termux-setup-storage

#bash ~/hello/termux/archlinux.sh --> We Do not need it anymore

bash ~/hello/termux/config.sh