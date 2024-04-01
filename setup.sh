# Deletes the Default Messages on the startup of the termux
cd ..
cd usr/etc
rm -rf motd 
# Goes to the main home....
cd ~/

# Installs the updates, and dependencies
yes | bash ~/hello/termux/package.sh

yes | termux-setup-storage
bash ~/hello/termux/archlinux.sh
bash ~/hello/termux/config.sh 