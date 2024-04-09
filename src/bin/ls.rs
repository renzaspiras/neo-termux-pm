use std::env;
use std::fs;

fn main() {
    // Retrieves command arguments
    let args: Vec<String> = env::args().collect();

    // Check if there are too many arguments
    if args.len() > 2 {
        println!("Too many arguments");
        return;
    }

    // If no arguments are provided, list files in the current directory
    if args.len() == 1 {
        match fs::read_dir(".") {
            Ok(entries) => {
                for entry in entries {
                    match entry {
                        Ok(entry) => println!("{:?}", entry.path()),
                        Err(e) => eprintln!("Error: {}", e),
                    }
                }
            }
            Err(e) => eprintln!("Error: {}", e),
        }
        return;
    }

    // If exactly one argument is provided, list files in the specified directory
    let path = &args[1];
    match fs::read_dir(path) {
        Ok(entries) => {
            for entry in entries {
                match entry {
                    Ok(entry) => println!("{:?}", entry.path()),
                    Err(e) => eprintln!("Error: {}", e),
                }
            }
        }
        Err(e) => eprintln!("Error: {}", e),
    }
}
