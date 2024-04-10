#!/bin/bash

# Array to store command history
command_history=()
history_index=-1

while true; do
    # Display prompt
    printf "> "
    # Read user input
    read -r -e -i "${command_history[$history_index]}" cmd_line

    # Add command to history
    if [ -n "$cmd_line" ]; then
        command_history+=("$cmd_line")
        history_index=$(( ${#command_history[@]} - 1 ))
    fi

    # Split command line into tokens
    IFS=' ' read -r -a tokens <<< "$cmd_line"

    # Execute built-in commands
    case "${tokens[0]}" in
        "exit")
            exit 0
            ;;
        "cd")
            if [ "${tokens[1]}" != "" ]; then
                cd "${tokens[1]}"
            else
                cd "$HOME"
            fi
            ;;
        *)
            # Execute external commands
            "${tokens[@]}"
            ;;
    esac

    # Handle key bindings for command history navigation
    while IFS= read -rsn1 key; do
        case "$key" in
            $'\e[A')  # Up arrow key
                if [ "$history_index" -gt 0 ]; then
                    ((history_index--))
                    cmd_line="${command_history[$history_index]}"
                    break
                fi
                ;;
            $'\e[B')  # Down arrow key
                if [ "$history_index" -lt "$((${#command_history[@]} - 1))" ]; then
                    ((history_index++))
                    cmd_line="${command_history[$history_index]}"
                    break
                fi
                ;;
        esac
    done
done
