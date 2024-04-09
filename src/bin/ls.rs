use std::env;

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
}