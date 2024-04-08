#!/bin/bash

# Infinite loop to continuously take user input and execute it
while true; do
    # Print the current working directory with color
    echo -e "\e[34m┌──[$PWD]\e[0m"  # Blue color for the directory prompt
    
    # Prompt the user to input a command
    read -p $'\e[32m└─$\e[0m ' command  # Green color for the command prompt
    
    # Check if the user wants to exit
    if [ "$command" == "exit" ]; then
        echo "Exiting..."
        break
    fi
    
    # Execute the command provided by the user if it exists
    if command -v "$command" &> /dev/null; then
        eval "$command"
    else
        # Display an error message if the command does not exist
        echo -e "\e[31mError: Command '$command' not found.\e[0m"  # Red color for the error message
    fi
done