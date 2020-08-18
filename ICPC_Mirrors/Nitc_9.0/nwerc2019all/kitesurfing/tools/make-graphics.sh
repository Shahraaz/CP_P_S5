#!/usr/bin/env bash

ghc TestCaseRenderer.hs
g++ -std=c++17 solve.cpp -o solve

for file in ../data/{sample,secret}/*.in; do
	echo
	echo ${file##*/}
	target=${file%.in}.png
	./solve < $file > tmp.ans || continue
	if [ -f $target ]; then
		echo Skipped
		continue
	fi
	cat $file tmp.ans | ./TestCaseRenderer -h 200 -o tmp.svg
	convert tmp.svg -flatten $target
	echo Done
done

rm -f TestCaseRenderer.o TestCaseRenderer.hi TestCaseRenderer
rm -f solve tmp.ans tmp.svg
