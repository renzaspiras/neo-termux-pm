#!/bin/bash

if [ "$1" == "neotermux" ]; then
  yes | bash ~/hello/neotermux/dependencies.sh
  bash ~/hello/neotermux/filesystem.sh
  python ~/hello/debug/compiler.py  
  touch storage/shared/TERMUX/TOKEN  