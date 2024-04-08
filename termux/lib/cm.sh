#!/bin/bash

# Infinite loop to continuously take user input and execute it
while true; do
    # Print the current working directory
    echo "┌──[$PWD]"
    
    # Prompt the user to input a command
    read -p "└─$ " command
    
    # Check if the user wants to exit
    if [ "$command" == "exit" ]; then
        echo "Exiting..."
        break
    fi
    
    # Execute the command provided by the user if it exists
    if command -v "$command" &> /dev/null; then
        eval "$command"
    else
        echo "Command not found in the binary system."
    fi
done
