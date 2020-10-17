#!/usr/bin/env bash
echo "Running 15 checker test(s)"
echo "Running 15 checker test(s)" 1> checker-tests.log
echo "Running test #1" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/01 files/tests/checker-tests/01.o files/tests/checker-tests/01.a 2>> checker-tests.log
if [ "$?" -ne "0" ]; then
    echo "Checker returned incorrect verdict. Expected: OK" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: OK. See checker-tests.log for checker comment"
    read
fi
echo "Running test #2" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/02 files/tests/checker-tests/02.o files/tests/checker-tests/02.a 2>> checker-tests.log
if [ "$?" -ne "0" ]; then
    echo "Checker returned incorrect verdict. Expected: OK" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: OK. See checker-tests.log for checker comment"
    read
fi
echo "Running test #3" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/03 files/tests/checker-tests/03.o files/tests/checker-tests/03.a 2>> checker-tests.log
if [ "$?" -ne "0" ]; then
    echo "Checker returned incorrect verdict. Expected: OK" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: OK. See checker-tests.log for checker comment"
    read
fi
echo "Running test #4" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/04 files/tests/checker-tests/04.o files/tests/checker-tests/04.a 2>> checker-tests.log
if [ "$?" -ne "1" ]; then
    echo "Checker returned incorrect verdict. Expected: Wrong answer" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Wrong answer. See checker-tests.log for checker comment"
    read
fi
echo "Running test #5" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/05 files/tests/checker-tests/05.o files/tests/checker-tests/05.a 2>> checker-tests.log
if [ "$?" -ne "2" ]; then
    echo "Checker returned incorrect verdict. Expected: Presentation error" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Presentation error. See checker-tests.log for checker comment"
    read
fi
echo "Running test #6" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/06 files/tests/checker-tests/06.o files/tests/checker-tests/06.a 2>> checker-tests.log
if [ "$?" -ne "3" ]; then
    echo "Checker returned incorrect verdict. Expected: Crashed" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Crashed. See checker-tests.log for checker comment"
    read
fi
echo "Running test #7" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/07 files/tests/checker-tests/07.o files/tests/checker-tests/07.a 2>> checker-tests.log
if [ "$?" -ne "1" ]; then
    echo "Checker returned incorrect verdict. Expected: Wrong answer" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Wrong answer. See checker-tests.log for checker comment"
    read
fi
echo "Running test #8" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/08 files/tests/checker-tests/08.o files/tests/checker-tests/08.a 2>> checker-tests.log
if [ "$?" -ne "1" ]; then
    echo "Checker returned incorrect verdict. Expected: Wrong answer" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Wrong answer. See checker-tests.log for checker comment"
    read
fi
echo "Running test #9" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/09 files/tests/checker-tests/09.o files/tests/checker-tests/09.a 2>> checker-tests.log
if [ "$?" -ne "1" ]; then
    echo "Checker returned incorrect verdict. Expected: Wrong answer" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Wrong answer. See checker-tests.log for checker comment"
    read
fi
echo "Running test #10" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/10 files/tests/checker-tests/10.o files/tests/checker-tests/10.a 2>> checker-tests.log
if [ "$?" -ne "1" ]; then
    echo "Checker returned incorrect verdict. Expected: Wrong answer" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Wrong answer. See checker-tests.log for checker comment"
    read
fi
echo "Running test #11" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/11 files/tests/checker-tests/11.o files/tests/checker-tests/11.a 2>> checker-tests.log
if [ "$?" -ne "2" ]; then
    echo "Checker returned incorrect verdict. Expected: Presentation error" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Presentation error. See checker-tests.log for checker comment"
    read
fi
echo "Running test #12" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/12 files/tests/checker-tests/12.o files/tests/checker-tests/12.a 2>> checker-tests.log
if [ "$?" -ne "1" ]; then
    echo "Checker returned incorrect verdict. Expected: Wrong answer" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Wrong answer. See checker-tests.log for checker comment"
    read
fi
echo "Running test #13" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/13 files/tests/checker-tests/13.o files/tests/checker-tests/13.a 2>> checker-tests.log
if [ "$?" -ne "1" ]; then
    echo "Checker returned incorrect verdict. Expected: Wrong answer" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Wrong answer. See checker-tests.log for checker comment"
    read
fi
echo "Running test #14" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/14 files/tests/checker-tests/14.o files/tests/checker-tests/14.a 2>> checker-tests.log
if [ "$?" -ne "1" ]; then
    echo "Checker returned incorrect verdict. Expected: Wrong answer" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Wrong answer. See checker-tests.log for checker comment"
    read
fi
echo "Running test #15" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/15 files/tests/checker-tests/15.o files/tests/checker-tests/15.a 2>> checker-tests.log
if [ "$?" -ne "3" ]; then
    echo "Checker returned incorrect verdict. Expected: Crashed" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Crashed. See checker-tests.log for checker comment"
    read
fi
rm -f checker-tests.log
echo "Checker test(s) finished"
