#!/bin/bash
clear

# Auto Fixes the .zshrc without reinstalling the entire system...
rm ~/.zshrc
wget https://raw.githubusercontent.com/renzaspiras/arch-termux/main/termux/.zshrc ~/.zshrc


# Define the directory containing all the directories to search
APPS_DIR="$HOME/apps"

# Check if APPS_DIR exists
if [ ! -d "$APPS_DIR" ]; then
    echo "Directory $APPS_DIR does not exist."
    exit 1
fi

# Get a list of directories in ~/apps
directories=$(find "$APPS_DIR" -maxdepth 1 -mindepth 1 -type d)


git clone https://github.com/renzaspiras/arch-termux.git ~/patch
cd ~/patch/patch/
bash layer0.sh

cd ..

rm -rf ~/patch