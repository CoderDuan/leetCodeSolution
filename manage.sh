#!/bin/bash

function printHelp() {
cat << HELP 
usage:
1. To create a leet code solution for problem #n:
    $0 create n
2. To delete a leet code solution for problem #n:
    $0 delete n
HELP
}

if [[ $# -lt 2 ]]; then
    printHelp $0
elif [[ $1 == "create" ]]; then
    var=$(echo $2 | bc 2>/dev/null)
    if [[ "$var" == $2 ]]; then
        newdir="leet_$2"
        echo $2 "$newdir"
        mkdir -p "$newdir"
        cp template/* $newdir/.
    else
        printHelp
    fi
elif [[ $1 == "delete" ]]; then
    var=$(echo $2 | bc 2>/dev/null)
    if [[ "$var" == $2 ]]; then
        rm -rf "leet_$2"
    else
        printHelp
    fi
fi