import os

binary = os.listdir("l/src/bin")

try:
  for j in binary:
    executable = j.split(".")[0]
    extention = j.split(".")[1]

    if(extention == "rs"):
      os.system(f"rustc src/bin/{j} -o ../../bin/{executable}")  
    elif(extention == "cpp"):
      os.system(f"g++ src/bin/{j} -o ../../bin/{executable}")
    elif(extention == "c++"):
      os.system(f"g++ src/bin/{j} -o ../../bin/{executable} -lncurses")
    elif(extention == "c"):
      os.system(f"gcc src/bin/{j} -o ../../bin/{executable}")
    elif(extention == "zig"):
      os.system(f"zig build-exe ../../bin/{j} -o bin/{executable}")      
except:
  pass