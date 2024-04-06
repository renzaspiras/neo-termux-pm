clear
# Package Directory
if [ ! -d "apps" ]; then
    # If not, create it
    bash .box.sh
    mkdir apps
    # echo "Directory 'apps' created."
else
    # echo "Directory 'apps' already exists."
fi

# Anti Bloat
[ -d "hello" ] && rm -r "hello"

# Package Manager
alias update='bash .box.sh'

alias add='git_clone_hello'
git_clone_hello() {
    git clone "$1" hello && cd hello && \
    if [ -f cm.sh ] && [ -f upcm.sh ] && [ -f cmrm.sh ]; then
        bash cm.sh
        bash upcm.sh
        bash cmrm.sh
        cd ..
        rm -rf hello
    else
        echo "It is not compatible with CM Console..."
        cd ..
        rm -rf hello
    fi
}

alias list='ls ~/apps'

alias remove='remove_package'
remove_package() {
    package="$1"
    if [ -d ~/apps/$package ]; then
        bash ~/apps/$package/cmrm.sh
        rm -rf ~/apps/$package
    else
        echo "Package does not exist"
    fi
}

zsh
exit