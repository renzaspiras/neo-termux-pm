import os

binary = os.listdir("./bin")

try:
  for j in binary:
    executable = j.split(".")[0]
    extention = j.split(".")[1]

    if(extention == "rs"):
      os.system(f"rustc ~/hello/bin/{j} -o ~/neo/bin/{executable}")  
    elif(extention == "cpp"):
      os.system(f"g++ ~/hello/bin/{j} -o ~/neo/bin/{executable}")
    elif(extention == "c++"):
      os.system(f"g++ ~/hello/bin/{j} -o ~/neo/bin/{executable} -lncurses")
    elif(extention == "c"):
      os.system(f"gcc ~/hello/bin/{j} -o ~/neo/bin/{executable}")
    elif(extention == "zig"):
      os.system(f"zig build-exe ~/hello/bin/{j} -o ~/neo/bin/{executable}")      
except:
  pass