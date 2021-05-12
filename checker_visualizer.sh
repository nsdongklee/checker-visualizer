#! /bin/bash

PSSH_DIR=./../push_swap
# export ARG='6 7 2 3 4 5 8 9 10 1';${PSSH_DIR} ${ARG} | python3 main.py
export ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`;${PSSH_DIR} ${ARG} | python3 main.py