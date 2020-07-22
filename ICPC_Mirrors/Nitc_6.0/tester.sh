#!/bin/bash
# input
# $1 excutable path
# $2 folder with *.in file

# output
# run $1 on all file in folder $2

curr=$(pwd)
cd $2
files=$(ls *.in)
cd $curr
for i in $files
do
    echo runnning on input $2/$i
    cat $2/$i
    echo ""
    echo "----------------------------------------"
    timeout 1 $1 < $2/$i
    echo "----------------------------------------"
done
