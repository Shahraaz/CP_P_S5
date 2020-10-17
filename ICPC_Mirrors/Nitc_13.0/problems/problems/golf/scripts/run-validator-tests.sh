#!/usr/bin/env bash
echo "Running 20 validator test(s)"
echo "Running 20 validator test(s)" 1> validator-tests.log
echo "Running test #1" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/01 2>> validator-tests.log
if [ "$?" -ne "0" ]; then
    echo "Validator returned non-zero exit code for a valid test" 1>> validator-tests.log
    echo "Validator returned non-zero exit code for a valid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #2" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/02 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #3" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/03 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #4" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/04 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #5" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/05 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #6" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/06 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #7" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/07 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #8" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/08 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #9" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/09 2>> validator-tests.log
if [ "$?" -ne "0" ]; then
    echo "Validator returned non-zero exit code for a valid test" 1>> validator-tests.log
    echo "Validator returned non-zero exit code for a valid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #10" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/10 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #11" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/11 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #12" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/12 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #13" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/13 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #14" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/14 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #15" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/15 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #16" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/16 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #17" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/17 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #18" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/18 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #19" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/19 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
echo "Running test #20" 1>> validator-tests.log
echo "Validator comment:" 1>> validator-tests.log
wine files/validate.exe < files/tests/validator-tests/20 2>> validator-tests.log
if [ "$?" -eq "0" ]; then
    echo "Validator returned zero exit code for a invalid test" 1>> validator-tests.log
    echo "Validator returned zero exit code for a invalid test. See validator-tests.log for validator comment"
    read
fi
rm -f validator-tests.log
echo "Validator test(s) finished"
