#! /bin/bash

export ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`;./push_swap_final/push_swap $ARG | python3 main.py
