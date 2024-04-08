#!/bin/bash

if [ "$1" == "neotermux" ]; then
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