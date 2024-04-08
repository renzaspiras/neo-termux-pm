use std::env;
use std::fs;

fn main(){
  //Retrieves command Arguments
  let args: Vec<String> = env::args().collect();


  let argument_total = args.len() - 1;
  let path = &args[1];

  if argument_total > 1{
    println!("Too Many Arguments");
  }

  else{
    if let Ok(metadata) = fs::metadata(&path) {
      if metadata.is_file(){
        //--> Everything starts here.....
        match fs::read_to_string(path){
          Ok(content) =>{
            println!("{}", content);
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
}