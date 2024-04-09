use std::env;
use std::fs;

/*
  Just a beginner rust programmer here!!!
  If you are a visitor. Please send me your feedback, it is just my hobby project to learn
*/


fn main(){
    // Retrieve command-line arguments
    let args: Vec<String> = env::args().collect();
    /*
      Sample agument
      args[0] the command itself
      args[1] the first argument
      args[2] the second argument
      args[3] the third argument
      
      
      println!("The directory is {}",args[1]);
      and so on......
     */    

    // Retrieves the total of arguments except the main command.....
    let argument_total = args.len()  -1;

    

    for num in 0..argument_total{
      match fs::create_dir(&args[num + 1]){
        Ok(_) => println!("\n"),
        Err(err) => eprintln!("{}",err),
      }
    }     
}