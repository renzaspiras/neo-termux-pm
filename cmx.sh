yes | pkg upgrade && yes | pkg install git && git clone https://github.com/renzaspiras/arch-termux.git hello && cd hello && bash setup.sh

mkdir storage/emulated/0/TERMUX
touch storage/emulated/0/TERMUX/token
