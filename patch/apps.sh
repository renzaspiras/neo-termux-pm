#!/bin/bash

# Define the directory containing the scripts
apps_dir=~/apps

# Iterate over subdirectories and run up.sh scripts
for app in "$apps_dir"/*; do
    if [ -d "$app" ]; then
        up_script="$app/up.sh"
        if [ -f "$up_script" ]; then
            bash "$up_script" &
        fi
    fi
done

# Wait for all background processes to finish
wait
