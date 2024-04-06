cp ~/hello/termux/.bashrc ~/.bashrc
yes | rm -r ~/hello
cd ~/
clear

mv ~/hello/termux/.zshrc ~/.zshrc
wget https://raw.githubusercontent.com/Sohil876/Termux-zsh/master/OhMyZsh/zshrc -O .omz.sh

touch storage/shared/TERMUX/TOKEN

echo "[DONE]"