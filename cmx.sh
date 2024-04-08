# The Installer of Android Termux
rm -rf hello
yes | pkg upgrade && yes | pkg install git && git clone https://github.com/renzaspiras/neo-termux-archlinux ~/hello && cd ~/hello && bash setup.sh
