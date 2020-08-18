#!/usr/bin/env bash

mkdir -p ../data/secret
g++ -Wall -O3 -std=c++17 ../submissions/accepted/bjarki.cpp -o sol

function seeded_tc {
    name="$1"
    shift
    seed="$1"
    shift
    gen="$1"
    shift
    echo "$name" "$gen" "$@"
    if [ "$gen" != "fixed" ]; then
        ./$gen "$@" "$seed" > ../data/secret/$name.in
    fi
    time ./sol < ../data/secret/$name.in > ../data/secret/$name.ans
}

function tc {
    seeded_tc "$1" "$@"
}

tc 01-precision fixed
tc 02-precision fixed
tc 03-boundary fixed
tc 04-boundary fixed
tc 05-boundary fixed
tc 06-boundary fixed
tc 07-boundary fixed
tc 08-boundary fixed
tc 09-boundary fixed
tc 10-boundary fixed
tc 11-boundary fixed

tc 11-uniform uniform.py
tc 12-uniform uniform.py
tc 13-uniform uniform.py
tc 14-uniform uniform.py
tc 15-uniform uniform.py
tc 16-uniform uniform.py
tc 17-uniform uniform.py
tc 18-uniform uniform.py
tc 19-uniform uniform.py
tc 20-uniform uniform.py
tc 21-uniform uniform.py

tc 22-duplicates-uniform duplicates.py uniform
tc 23-duplicates-uniform duplicates.py uniform
tc 24-duplicates-uniform duplicates.py uniform
tc 25-duplicates-uniform duplicates.py uniform
tc 26-duplicates-uniform duplicates.py uniform
tc 27-duplicates-uniform duplicates.py uniform
tc 28-duplicates-uniform duplicates.py uniform
tc 29-duplicates-uniform duplicates.py uniform
tc 30-duplicates-uniform duplicates.py uniform
tc 31-duplicates-uniform duplicates.py uniform

tc 32-duplicates-from-list duplicates.py from_list
tc 33-duplicates-from-list duplicates.py from_list
tc 34-duplicates-from-list duplicates.py from_list
tc 35-duplicates-from-list duplicates.py from_list
tc 36-duplicates-from-list duplicates.py from_list
tc 37-duplicates-from-list duplicates.py from_list
tc 38-duplicates-from-list duplicates.py from_list
tc 39-duplicates-from-list duplicates.py from_list
tc 40-duplicates-from-list duplicates.py from_list
tc 41-duplicates-from-list duplicates.py from_list

tc 42-uniform-possible uniform-possible.py
tc 43-uniform-possible uniform-possible.py
tc 44-uniform-possible uniform-possible.py
tc 45-uniform-possible uniform-possible.py
tc 46-uniform-possible uniform-possible.py
tc 47-uniform-possible uniform-possible.py
tc 48-uniform-possible uniform-possible.py
tc 49-uniform-possible uniform-possible.py
tc 50-uniform-possible uniform-possible.py
tc 51-uniform-possible uniform-possible.py
tc 52-uniform-possible uniform-possible.py

tc 53-max-output fixed
tc 54-min-output fixed

tc 55-max-t fixed
tc 56-min-t fixed

