use std::env;
use std::fs;

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

  if let Ok(metadata) = fs::metadata(&path) {
    if metadata.is_file(){
      //--> Everything starts here.....
      match fs::read_to_string(path){
        Ok(content) =>{
          println!("{}\n", content);
        }
        Err(err) =>{
          eprintln!("Error reading file: {}", err);
        }
      }
    }
    else if metadata.is_dir(){
      println!("{} is a directory", &path);
    }
    else{
      println!("No Such File on directory");
    }
  }
  else{
    println!("No Such File on directory");
  }  
}