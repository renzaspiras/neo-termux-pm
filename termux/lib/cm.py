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
    
    elif command == "get update":
        os.system("yes | pkg upgrade && yes | pkg install git && git clone https://github.com/renzaspiras/arch-termux.git ~/hello && bash ~/hello/setup.sh")
        
    try:
        output = os.popen(command).read()
        print(output)
    except Exception as e:
        # Display an error message if there's an exception
        print("\033[31mError: {}\033[0m".format(e))  # Red color for the error message