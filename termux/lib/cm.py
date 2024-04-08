import os

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
    
    elif command == "get":
        print("pkg update [updates the system]")
        print("pkg add [install an app that is compatible)]")

    elif command == "get update":
        os.system("yes | pkg upgrade && yes | pkg install git && git clone https://github.com/renzaspiras/neo-termux-archlinux.git ~/hello && bash ~/hello/setup.sh")
        os.system("rm -rf ~/hello")

    elif command.startswith("cd "):
        try:
            directory = command.split(" ")[1]
            os.chdir(directory)
        except Exception as e:
            print("\033[31mError: {}\033[0m".format(e))  # Red color for the error message
        continue

    try:
        output = os.popen(command).read()
        print(output)
    except Exception as e:
        # Display an error message if there's an exception
        print("\033[31mError: {}\033[0m".format(e))  # Red color for the error message