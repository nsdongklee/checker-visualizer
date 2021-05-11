#! /bin/bash


export ARG=`ruby -e "puts (0..20).to_a.shuffle.join(' ')"`;./push_swap_final/push_swap $ARG | python3 main.py
# export ARG=`3 2 1 4 5 0`;./push_swap_final/push_swap $ARG | python3 main.py
