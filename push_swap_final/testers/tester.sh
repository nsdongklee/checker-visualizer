#! /bin/bash

ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`
#ARG="3 2 1 4 5"; ./push_swap $ARG | ./checker $ARG
# ./push_swap $ARG
# leaks -atExit -- ./push_swap $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
