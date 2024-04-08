clear

bash storage/shared/TERMUX/filesystem/etc/cm.sh

file_path="storage/shared/TERMUX/TOKEN"

if [ -f "$file_path" ]; then
    exit
else
    # File does not exist, so ignore
fi