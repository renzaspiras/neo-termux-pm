#!/bin/bash

if [ "$1" == "neotermux" ]; then
  bash ~/hello/neotermux/dependencies.sh
  bash ~/hello/neotermux/filesystem.sh
  python ~/hello/debug/compiler.py  

elif [ "$1" == "debug" ]; then
  mkdir compiled
  mkdir ../bin
  python ./debug/compiler.py
  mv ./compiled/* ../bin

  ../bin/shell

else
  echo "not"
fi