cd ..
cd usr/etc
rm -rf motd

cd ~/

yes | bash ./termux/package.sh
termux-setup-storage
bash ./termux/archlinux.sh
bash ./termux/config.sh