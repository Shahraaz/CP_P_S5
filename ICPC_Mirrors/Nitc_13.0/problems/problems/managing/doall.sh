#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir -p tests
echo "Generating test #2"
scripts/gen-input-via-stdout.sh "wine files/g2.exe 10 3 4" "tests/02" 2
echo "Generating test #3"
scripts/gen-input-via-stdout.sh "wine files/g2.exe 10 5 6" "tests/03" 3
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "wine files/g2.exe 10 10 10" "tests/04" 4
echo "Generating test #5"
scripts/gen-input-via-stdout.sh "wine files/g2.exe 10 2000 1000" "tests/05" 5
echo "Generating test #6"
scripts/gen-input-via-stdout.sh "wine files/g.exe 10 2000 1000" "tests/06" 6
echo "Generating test #7"
scripts/gen-input-via-stdout.sh "wine files/g.exe 10 2000 10000" "tests/07" 7
echo "Generating test #8"
scripts/gen-input-via-stdout.sh "wine files/g.exe 10 2000 100000" "tests/08" 8
echo "Generating test #9"
scripts/gen-input-via-stdout.sh "wine files/g.exe 10 2000 1" "tests/09" 9
echo ""
echo "Generating answer for test #1"
scripts/gen-answer.sh tests/01 tests/01.a "tests" ""
echo ""
echo "Generating answer for test #2"
scripts/gen-answer.sh tests/02 tests/02.a "tests" ""
echo ""
echo "Generating answer for test #3"
scripts/gen-answer.sh tests/03 tests/03.a "tests" ""
echo ""
echo "Generating answer for test #4"
scripts/gen-answer.sh tests/04 tests/04.a "tests" ""
echo ""
echo "Generating answer for test #5"
scripts/gen-answer.sh tests/05 tests/05.a "tests" ""
echo ""
echo "Generating answer for test #6"
scripts/gen-answer.sh tests/06 tests/06.a "tests" ""
echo ""
echo "Generating answer for test #7"
scripts/gen-answer.sh tests/07 tests/07.a "tests" ""
echo ""
echo "Generating answer for test #8"
scripts/gen-answer.sh tests/08 tests/08.a "tests" ""
echo ""
echo "Generating answer for test #9"
scripts/gen-answer.sh tests/09 tests/09.a "tests" ""
echo ""

