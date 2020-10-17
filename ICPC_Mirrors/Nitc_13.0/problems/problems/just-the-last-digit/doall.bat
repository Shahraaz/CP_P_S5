rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 2 0" "tests\02" 2
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 2 1" "tests\03" 3
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 3 0" "tests\04" 4
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 3 1" "tests\05" 5
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 4 0" "tests\06" 6
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 4 0.5" "tests\07" 7
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 4 1" "tests\08" 8
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 5 0.1" "tests\09" 9
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 6 0.9" "tests\10" 10
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 7 0.8" "tests\11" 11
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 8 0.7" "tests\12" 12
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 20 0.3" "tests\13" 13
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 100 0.2" "tests\14" 14
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 250 0.1" "tests\15" 15
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 500 0" "tests\16" 16
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 500 0.01" "tests\17" 17
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 500 0.1" "tests\18" 18
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 500 0.3" "tests\19" 19
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 500 0.5" "tests\20" 20
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 500 0.8" "tests\21" 21
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 500 0.99" "tests\22" 22
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 500 0.999" "tests\23" 23
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\GenRandom.jar 500 1" "tests\24" 24
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""
call scripts\gen-answer.bat tests\02 tests\02.a "tests" ""
call scripts\gen-answer.bat tests\03 tests\03.a "tests" ""
call scripts\gen-answer.bat tests\04 tests\04.a "tests" ""
call scripts\gen-answer.bat tests\05 tests\05.a "tests" ""
call scripts\gen-answer.bat tests\06 tests\06.a "tests" ""
call scripts\gen-answer.bat tests\07 tests\07.a "tests" ""
call scripts\gen-answer.bat tests\08 tests\08.a "tests" ""
call scripts\gen-answer.bat tests\09 tests\09.a "tests" ""
call scripts\gen-answer.bat tests\10 tests\10.a "tests" ""
call scripts\gen-answer.bat tests\11 tests\11.a "tests" ""
call scripts\gen-answer.bat tests\12 tests\12.a "tests" ""
call scripts\gen-answer.bat tests\13 tests\13.a "tests" ""
call scripts\gen-answer.bat tests\14 tests\14.a "tests" ""
call scripts\gen-answer.bat tests\15 tests\15.a "tests" ""
call scripts\gen-answer.bat tests\16 tests\16.a "tests" ""
call scripts\gen-answer.bat tests\17 tests\17.a "tests" ""
call scripts\gen-answer.bat tests\18 tests\18.a "tests" ""
call scripts\gen-answer.bat tests\19 tests\19.a "tests" ""
call scripts\gen-answer.bat tests\20 tests\20.a "tests" ""
call scripts\gen-answer.bat tests\21 tests\21.a "tests" ""
call scripts\gen-answer.bat tests\22 tests\22.a "tests" ""
call scripts\gen-answer.bat tests\23 tests\23.a "tests" ""
call scripts\gen-answer.bat tests\24 tests\24.a "tests" ""

