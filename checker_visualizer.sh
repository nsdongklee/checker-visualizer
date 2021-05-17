#! /bin/bash

PSSW_DIR=./../push_swap
# export ARG='6 7 2 3 4 5 8 9 10 1';${PSSW_DIR} ${ARG} | python3 main.py
export ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`;${PSSW_DIR} ${ARG} | python3 main.py
