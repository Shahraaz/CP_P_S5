rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=1 c=1" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=1" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=2 c=2" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=2" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=3 c=3" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=3" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=4 c=4" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=4" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=5 c=5" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=5" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=10 c=10" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=10" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=30 c=30" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=30" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=100 c=100" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=100" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=300 c=300" "tests\27" 27
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=300" "tests\28" 28
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=1000 c=1000" "tests\29" 29
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=1000" "tests\30" 30
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=1000 c=1" "tests\31" 31
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=1000 c=30" "tests\32" 32
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=1000 h=1" "tests\33" 33
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=1000 h=10" "tests\34" 34
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rand n=999 c=5 h=10000000" "tests\35" 35
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Max n=1000 c=10000000" "tests\36" 36
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rect n=1000 h=10000000 xl=23 xr=23 yl=0 yr=10000000" "tests\37" 37
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rect n=1000 h=10000000 xl=-10000000 xr=10000000 yl=0 yr=0" "tests\38" 38
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Rect n=1000 h=1111 xl=-1000000 xr=1000000 yl=-10000000 yr=10000000" "tests\39" 39
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Line n=1000 x1=0 y1=0 x2=10000000 y2=1000000" "tests\40" 40
call scripts\gen-input-via-stdout.bat "files\gen.exe type=Line n=1000 x1=0 y1=0 x2=239 y2=1000000" "tests\41" 41
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
call scripts\gen-answer.bat tests\41 tests\41.a "tests" ""

