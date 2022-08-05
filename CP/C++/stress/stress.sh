#!/usr/bin/env bash

for ((testNum=0;testNum<$4;testNum++))
do
    ./$3 > in
    ./$2 < in > outSlow
    ./$1 < in > outWrong
    H1=`md5sum outWrong`
    H2=`md5sum outSlow`
    if !(cmp -s "outWrong" "outSlow")
    then
        echo "Error found!"
        echo "Input:"
        cat in
        echo "Wrong Output:"
        cat outWrong
        echo "Slow Output:"
        cat outSlow
        exit
    fi
    echo $testNum
done
echo Passed $4 tests

