cd ..
cd usr/etc
rm -rf motd

cd ~/

yes | bash ~/hello/termux/package.sh
yes | termux-setup-storage
bash ~/hello/termux/archlinux.sh
bash ~/hello/termux/config.sh