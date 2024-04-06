cp ~/hello/termux/.bashrc ~/.bashrc
yes | rm -r ~/hello
cd ~/
clear

git clone https://github.com/Sohil876/Termux-zsh.git zsh
cd zsh
yes | bash setup.sh
cd ~/


touch storage/shared/TERMUX/TOKEN

echo "Done Installing. You May Now Type [Exit] and [Enter]"
exit
