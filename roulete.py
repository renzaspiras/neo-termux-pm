import random

lang = [
  "c",
  "c++",
  "zig",
  "rust"
]

todo = [
  "shell", #--> Using C++
  "ls",
  "cd",
  #"mkdir", --> Done using Rust....
  # "cat", --> Done using Rust...
  "pwd",
  "cp",
  "mv",
  "grep",
  "kill",
  "pacman"
]

language = lang[(random.randint(0, len(lang))) -1]
what = todo[(random.randint(0, len(todo)))-1]

print(f"We will use {language} to make {what}")