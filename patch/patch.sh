#!/bin/bash
clear

# Auto Fixes the .zshrc without reinstalling the entire system...
rm ~/.zshrc
wget https://raw.githubusercontent.com/renzaspiras/arch-termux/main/termux/.zshrc ~/.zshrc


# Define the directory containing all the directories to search
APPS_DIR="~/apps"

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
