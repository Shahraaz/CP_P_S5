#!/usr/bin/env bash

mkdir -p ../data/secret
g++ -Wall -O3 -std=c++17 ../submissions/accepted/bjarki_dp.cpp -o sol

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

tc 01-random-graph uniform_graph.py 10 10
tc 02-random-graph uniform_graph.py 10 30
tc 03-random-graph uniform_graph.py 10 40
tc 04-random-graph uniform_graph.py 141 2500
tc 05-random-graph uniform_graph.py 141 5000
tc 06-random-graph uniform_graph.py 141 9000
tc 07-random-graph uniform_graph.py 141 9500
tc 08-random-graph uniform_graph.py 141 9800
tc 09-random-graph uniform_graph.py 141 9870
tc 10-random-graph uniform_graph.py 500 1000
tc 11-random-graph uniform_graph.py 500 5000
tc 12-random-graph uniform_graph.py 500 8000
tc 13-random-graph uniform_graph.py 500 10000
tc 14-random-graph uniform_graph.py 1000 10000
tc 15-random-graph uniform_graph.py 1500 10000
tc 16-random-graph uniform_graph.py 2000 2500
tc 17-random-graph uniform_graph.py 2000 4000
tc 18-random-graph uniform_graph.py 2000 5000
tc 19-random-graph uniform_graph.py 2000 8000
tc 20-random-graph uniform_graph.py 2000 9000
tc 21-random-graph uniform_graph.py 2000 10000
tc 22-random-tree uniform_tree.py 10
tc 23-random-tree uniform_tree.py 100
tc 24-random-tree uniform_tree.py 500
tc 25-random-tree uniform_tree.py 1000
tc 26-random-tree uniform_tree.py 1500
tc 27-random-tree uniform_tree.py 2000
tc 28-overflow fixed
tc 29-small-tree fixed
tc 30-ratio ratio.py 998244353 497 0
tc 31-ratio ratio.py 998244353 497 1
tc 32-large-intersection large_intersection.py 2000
tc 33-path path.py 2000 1 1000000000 0 0
tc 34-path path.py 2000 1000000000 1000000000 0 0
tc 35-path path.py 2000 1 1000000000 1 0
tc 36-path path.py 2000 1000000000 1000000000 1 0
tc 37-path path.py 2000 1 500000 1 1
tc 38-path path.py 2000 500000 500000 1 1
tc 39-triangles triangle_chain.py 2000 10000 0
tc 40-triangles triangle_chain.py 2000 10000 2
tc 41-triangles triangle_chain.py 2000 10000 10
tc 42-triangles triangle_chain.py 2000 10000 1000000000
tc 43-many-path-lengths fixed
tc 44-lines lines.py
tc 45-lines lines.py
tc 46-lines lines.py
tc 47-lines lines.py
tc 48-lines lines.py
tc 49-lines lines.py
tc 50-lines lines.py
tc 60-epsilon kill_epsilon.py 333 0
tc 61-epsilon kill_epsilon.py 333 1
tc 70-per fixed
tc 71-per fixed
tc 80-path-ragnar path_ragnar.py 2000 10000 path
tc 81-fractal fractal.py random
tc 82-fractal fractal.py random
tc 83-fractal fractal.py exact
tc 84-fractal fractal.py exact
tc 85-fractal fractal.py bias
tc 86-fractal fractal.py bias
tc 87-fractal fractal.py bias
tc 88-fractal fractal_incremental.py random
tc 89-fractal fractal_incremental.py random
tc 90-fractal fractal_incremental.py exact
tc 91-fractal fractal_incremental.py exact
tc 92-fractal fractal_incremental.py bias
tc 93-fractal fractal_incremental.py bias
tc 94-fractal fractal_incremental.py bias
tc 95-path-ragnar-long path_ragnar.py 2000 10000 random_path
# A path 1...n, random edges j->i for all i, and random edges
tc 96_ragnar_3 fixed
# Same, but with quadratic weights
tc 97_ragnar_4 fixed
tc 98-smallest-graph fixed
tc 99-smallest-graph fixed
