#!/usr/bin/env bash
echo "Running 7 checker test(s)"
echo "Running 7 checker test(s)" 1> checker-tests.log
echo "Running test #1" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar check.jar files/tests/checker-tests/01 files/tests/checker-tests/01.o files/tests/checker-tests/01.a 2>> checker-tests.log
if [ "$?" -ne "0" ]; then
    echo "Checker returned incorrect verdict. Expected: OK" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: OK. See checker-tests.log for checker comment"
    read
fi
echo "Running test #2" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar check.jar files/tests/checker-tests/02 files/tests/checker-tests/02.o files/tests/checker-tests/02.a 2>> checker-tests.log
if [ "$?" -ne "0" ]; then
    echo "Checker returned incorrect verdict. Expected: OK" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: OK. See checker-tests.log for checker comment"
    read
fi
echo "Running test #3" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar check.jar files/tests/checker-tests/03 files/tests/checker-tests/03.o files/tests/checker-tests/03.a 2>> checker-tests.log
if [ "$?" -ne "1" ]; then
    echo "Checker returned incorrect verdict. Expected: Wrong answer" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Wrong answer. See checker-tests.log for checker comment"
    read
fi
echo "Running test #4" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar check.jar files/tests/checker-tests/04 files/tests/checker-tests/04.o files/tests/checker-tests/04.a 2>> checker-tests.log
if [ "$?" -ne "1" ]; then
    echo "Checker returned incorrect verdict. Expected: Wrong answer" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Wrong answer. See checker-tests.log for checker comment"
    read
fi
echo "Running test #5" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar check.jar files/tests/checker-tests/05 files/tests/checker-tests/05.o files/tests/checker-tests/05.a 2>> checker-tests.log
if [ "$?" -ne "0" ]; then
    echo "Checker returned incorrect verdict. Expected: OK" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: OK. See checker-tests.log for checker comment"
    read
fi
echo "Running test #6" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar check.jar files/tests/checker-tests/06 files/tests/checker-tests/06.o files/tests/checker-tests/06.a 2>> checker-tests.log
if [ "$?" -ne "0" ]; then
    echo "Checker returned incorrect verdict. Expected: OK" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: OK. See checker-tests.log for checker comment"
    read
fi
echo "Running test #7" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar check.jar files/tests/checker-tests/07 files/tests/checker-tests/07.o files/tests/checker-tests/07.a 2>> checker-tests.log
if [ "$?" -ne "0" ]; then
    echo "Checker returned incorrect verdict. Expected: OK" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: OK. See checker-tests.log for checker comment"
    read
fi
rm -f checker-tests.log
echo "Checker test(s) finished"
