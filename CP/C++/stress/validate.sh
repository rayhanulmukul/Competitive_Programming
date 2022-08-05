#!/usr/bin/env bash

for ((testNum=0;testNum<$4;testNum++))
do
    ./$3 > in
    ./$1 < in > out
    cat in out > data
    ./$2 < data > res
    result=$(cat res)
    if [ "${result:0:2}" != "OK" ];
    then
        echo "Error found!"
        echo "Input:"
        cat in
        echo "Output:"
        cat out
        echo "Validator Result:"
        cat res 
        exit
    fi
    echo $testNum
done
echo Passed $4 tests

