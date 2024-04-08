import os
import readline

# Define a function to handle key press events
def key_pressed(event):
    if event.keycode == 38:  # Up arrow key
        if readline.get_current_history_length() > 1:
            readline.replace_line(readline.get_history_item(readline.get_current_history_length() - 2))
            readline.redisplay()
    elif event.keycode == 40:  # Down arrow key
        if readline.get_current_history_length() > readline.get_current_history_index() + 1:
            readline.replace_line(readline.get_history_item(readline.get_current_history_index() + 1))
            readline.redisplay()

# Bind the function to handle key press events
readline.parse_and_bind('<KeyPress>?: "\033[38~"')
readline.parse_and_bind('<KeyPress>?: "\033[40~"')

# Infinite loop to continuously take user input and execute it
while True:
    # Print the current working directory with color
    print("\033[34m┌──[{}]\033[0m".format(os.getcwd()))  # Blue color for the directory prompt
    
    # Prompt the user to input a command
    command = input("\033[32m└─$\033[0m ")  # Green color for the command prompt

    # Check if the user wants to exit
    if command == "exit":
        print("Exiting...")
        break    

    # Temporary Updater
    elif command == "get update":    
        os.system("git clone https://github.com/renzaspiras/neo-termux-archlinux.git ~/hello && bash ~/hello/setup.sh")
        os.system("rm -rf ~/hello")

    elif command.startswith("cd "):
        try:
            directory = command.split(" ")[1]
            os.chdir(directory)
        except Exception as e:
            print("\033[31mError: {}\033[0m".format(e))  # Red color for the error message
        continue

    elif command == "":  # If the user presses Enter without typing anything
        continue

    else:
        try:
            output = os.popen("./storage/shared/TERMUX/filesystem/bin/" + command).read()
            #print(output)
        except Exception as e:
            # Display an error message if there's an exception
            print("\033[31mError: {}\033[0m".format(e))  # Red color for the error message

    # Add the command to the history
    readline.add_history(command)