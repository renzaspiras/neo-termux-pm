import random

lang = [
  "c",
  "c++",
  "zig",
  "rust"
]

todo = [
  "shell", #--> Using C++
  "ls", # --> zig
  "cd", # --> using cp
  #"mkdir", --> Done using Rust....
  # "cat", --> Done using Rust...
  "pwd", # --> using C
  "cp", # --> using C
  "mv", # --> using C++
  "grep", # --> using Rust
  "kill", # --> using C
  "pacman" # --> using C
]

language = lang[(random.randint(0, len(lang))) -1]
what = todo[(random.randint(0, len(todo)))-1]

print(f"We will use {language} to make {what}")