use std::env;
use std::fs;

fn main() {
    // Retrieves command arguments
    let args: Vec<String> = env::args().collect();

    if args.len() != 2 {
        println!("Usage: {} <directory>", args[0]);
        return;
    }

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
