rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 10 2 rand rand" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 10 2 rand yes" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 10 10 rand rand" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 10 10 rand yes" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 10 10 rand shuffle" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 10 10 rand shuffle seed17" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 2 rand rand" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 2 rand yes" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 2 rand shuffle" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 3 rand rand" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 3 rand yes" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 3 rand shuffle" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 10 rand rand" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 10 rand yes" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 10 rand shuffle" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 50 rand rand" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 50 rand yes" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 50 rand shuffle" "tests\27" 27
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 100 rand rand" "tests\28" 28
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 100 rand yes" "tests\29" 29
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 100 rand shuffle" "tests\30" 30
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 100 perm yes" "tests\31" 31
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 100 perm same" "tests\32" 32
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 100 perm rand" "tests\33" 33
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 100 perm shuffle" "tests\34" 34
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 2 01 10" "tests\35" 35
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 49 2 01 10" "tests\36" 36
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 2 rand 10" "tests\37" 37
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 49 2 rand 10" "tests\38" 38
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 2 10 rand" "tests\39" 39
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 49 2 10 rand" "tests\40" 40
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
call scripts\gen-answer.bat tests\25 tests\25.a "tests" ""
call scripts\gen-answer.bat tests\26 tests\26.a "tests" ""
call scripts\gen-answer.bat tests\27 tests\27.a "tests" ""
call scripts\gen-answer.bat tests\28 tests\28.a "tests" ""
call scripts\gen-answer.bat tests\29 tests\29.a "tests" ""
call scripts\gen-answer.bat tests\30 tests\30.a "tests" ""
call scripts\gen-answer.bat tests\31 tests\31.a "tests" ""
call scripts\gen-answer.bat tests\32 tests\32.a "tests" ""
call scripts\gen-answer.bat tests\33 tests\33.a "tests" ""
call scripts\gen-answer.bat tests\34 tests\34.a "tests" ""
call scripts\gen-answer.bat tests\35 tests\35.a "tests" ""
call scripts\gen-answer.bat tests\36 tests\36.a "tests" ""
call scripts\gen-answer.bat tests\37 tests\37.a "tests" ""
call scripts\gen-answer.bat tests\38 tests\38.a "tests" ""
call scripts\gen-answer.bat tests\39 tests\39.a "tests" ""
call scripts\gen-answer.bat tests\40 tests\40.a "tests" ""

