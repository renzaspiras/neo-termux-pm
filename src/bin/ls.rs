use std::env;
use std::fs;
use std::path::Path;

fn main(){
    //Retrieves command Arguments
    let args: Vec<String> = env::args().collect();

    if args.len() == 1 {
        println!("No arguments provided");
        return; // Exit the program early
    }
    else if args.len() > 2{
        println!("Too Many Arguments");
        return;
    }
    
    let path = &args[1];
    match fs::read_dir(Path::new(path)) {
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