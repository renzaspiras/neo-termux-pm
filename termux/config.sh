cp ~/hello/termux/.bashrc ~/.bashrc
yes | rm -r ~/hello
cd ~/
clear

git clone https://github.com/renzaspiras/Termux-zsh.git zsh
cd zsh
yes | bash setup.sh
yes | rm -r ~/zsh
cd ~/

touch storage/shared/TERMUX/TOKEN

echo "[DONE]"
