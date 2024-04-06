# Deletes the Default Messages on the startup of the termux
cd ..
cd usr/etc
rm -rf motd

# Goes to the main home....
cd ~/

# Installs the updates, and dependencies
yes | bash ~/hello/termux/package.sh


yes | termux-setup-storage

# yes | bash ~/hello/patch/layer0.sh
echo 'alias update="wget https://raw.githubusercontent.com/renzaspiras/arch-termux/main/patch/patch.sh -O /path/to/save/patch.sh && bash /path/to/save/patch.sh"' >> ~/.zshrc
source ~/.zshrc


bash ~/hello/termux/config.sh 