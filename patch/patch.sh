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

# Iterate over each directory
for dir in $directories; do
    # Extract directory name
    dir_name=$(basename "$dir")
    
    # Check if upcm.sh exists in the directory
    if [ -f "$dir/upcm.sh" ]; then
        echo "Running upcm.sh in directory $dir_name"
        # Run upcm.sh
        bash "$dir/upcm.sh"
    else
        echo "upcm.sh not found in directory $dir_name"
    fi
done

# Check if cmake is installed
if ! command -v cmake &> /dev/null; then
    echo "cmake is not installed. Installing..."
    pacman -S cmake --noconfirm
else
    echo "cmake is already installed."
fi

# Check if jsoncpp-doc is installed
if ! pacman -Qs jsoncpp-doc &> /dev/null; then
    echo "jsoncpp-doc is not installed. Installing..."
    pacman -S jsoncpp-doc --noconfirm
else
    echo "jsoncpp-doc is already installed."
fi


git clone https://github.com/renzaspiras/arch-termux.git ~/patch
cd ~/patch/patch/
bash layer0.sh

cd ..

rm ~/patch