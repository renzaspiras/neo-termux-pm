#!/bin/bash

if [ "$1" == "neotermux" ]; then
  python ~/hello/debug/compiler.py  

elif [ "$1" == "debug" ]; then
  mkdir compiled
  python ./debug/compiler.py

else
  echo "not"
fi