rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen_a.exe 200000" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 100" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 5000" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 200000" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen_thue.exe 5000" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen_thue.exe 200000" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen_thue_blocks.exe 5000" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen_thue_blocks.exe 200000" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 1000 239 31" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 5000 3121 2923" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 5000 2325 12" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 5000 14 9" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 5000 3 1" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 5000 5000 1000" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 5000 5000 4999" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 200000 322 228" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 200000 19 3" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 200000 6 2" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 200000 15511 2323" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 200000 151851 31515" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 200000 200000 40000" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 200000 200000 12" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 200000 170000 1512" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\gen_ans_1.exe 200000 100000 135" "tests\27" 27
call scripts\gen-input-via-stdout.bat "files\gen_dq.exe 127" "tests\28" 28
call scripts\gen-input-via-stdout.bat "files\gen_dq.exe 4095" "tests\29" 29
call scripts\gen-input-via-stdout.bat "files\gen_dq.exe 131071" "tests\30" 30
call scripts\gen-input-via-stdout.bat "files\gen_dq.exe 199999" "tests\31" 31
call scripts\gen-input-via-stdout.bat "files\gen_dq.exe 200000" "tests\32" 32
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

