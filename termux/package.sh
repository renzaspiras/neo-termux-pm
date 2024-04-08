# Languages
pkg install python
pkg install clang

# Utility
pkg install git
pkg install wget

mv ~/hello/patch/cm-utils.c ~/cm.c
gcc ~/cm.c -o ~/cm
mv ~/cm ~/neo/bin/cm
rm cm.c