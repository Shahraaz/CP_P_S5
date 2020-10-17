rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=10 max_m=10 type=random ans_exist=true 1111" "tests\03" 3
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=20 max_m=20 type=random ans_exist=true 112" "tests\04" 4
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=30 max_m=30 type=random ans_exist=true 1122" "tests\05" 5
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=40 max_m=40 type=random ans_exist=true 1124" "tests\06" 6
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=50 max_m=50 type=random ans_exist=true 1126" "tests\07" 7
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=50 max_m=50 type=random ans_exist=false 11265" "tests\08" 8
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=100000 max_m=100000 type=random ans_exist=true 11442" "tests\09" 9
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=200000 type=random ans_exist=true 114424" "tests\10" 10
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=100000 type=random ans_exist=true 114442" "tests\11" 11
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=200000 type=random ans_exist=true 1144421" "tests\12" 12
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=200000 type=random ans_exist=true 1144422" "tests\13" 13
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=200000 type=random ans_exist=true 1144423" "tests\14" 14
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=50000 type=spec1 use_max=true ans_exist=true 11111" "tests\15" 15
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=10000 type=spec1 use_max=true ans_exist=true 11112" "tests\16" 16
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=20000 type=spec1 use_max=true ans_exist=true 11113" "tests\17" 17
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=100 type=spec1 use_max=true ans_exist=true 11114" "tests\18" 18
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=100000 type=spec1 use_max=true ans_exist=true 11153" "tests\19" 19
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=190000 type=spec1 use_max=true ans_exist=true 11164" "tests\20" 20
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=190000 type=spec1 use_max=true ans_exist=false 111642" "tests\21" 21
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=10000 type=spec1 use_max=true ans_exist=false 111644" "tests\22" 22
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=50000 type=spec1 use_max=true ans_exist=false 111645" "tests\23" 23
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=100000 type=spec1 use_max=true ans_exist=false 111646" "tests\24" 24
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=2 type=one_line use_max=true 1231" "tests\25" 25
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=3 type=one_line use_max=true 1232" "tests\26" 26
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=5 type=one_line use_max=true 1233" "tests\27" 27
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=1000 type=one_line use_max=true 1234" "tests\28" 28
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=200000 type=one_line use_max=true 1235" "tests\29" 29
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=199000 type=one_line use_max=true 1236" "tests\30" 30
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 type=full_binary use_max=true ans_exist=true 234324" "tests\31" 31
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 type=full_binary use_max=true ans_exist=true 2343241" "tests\32" 32
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 type=full_binary use_max=true ans_exist=true 2343242" "tests\33" 33
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=3 type=full_binary use_max=true ans_exist=false 23432" "tests\34" 34
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=4 type=full_binary use_max=true ans_exist=false 234321" "tests\35" 35
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=5 type=full_binary use_max=true ans_exist=false 234322" "tests\36" 36
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=10 type=full_binary use_max=true ans_exist=false 234323" "tests\37" 37
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=20 type=full_binary use_max=true ans_exist=false 234324" "tests\38" 38
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=50 type=full_binary use_max=true ans_exist=false 234325" "tests\39" 39
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=1000 type=full_binary use_max=true ans_exist=false 234326" "tests\40" 40
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=100000 type=full_binary use_max=true ans_exist=false 234326" "tests\41" 41
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=200000 type=full_binary use_max=true ans_exist=false 234326" "tests\42" 42
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=3 type=sun use_max=true ans_exist=true 1111221" "tests\43" 43
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=4 type=sun use_max=true ans_exist=true 1111222" "tests\44" 44
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=5 type=sun use_max=true ans_exist=true 1111223" "tests\45" 45
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=10 type=sun use_max=true ans_exist=true 1111224" "tests\46" 46
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=50 type=sun use_max=true ans_exist=true 1111225" "tests\47" 47
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=150 type=sun use_max=true ans_exist=true 1111226" "tests\48" 48
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=500 type=sun use_max=true ans_exist=true 1111227" "tests\49" 49
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=10000 type=sun use_max=true ans_exist=true 1111228" "tests\50" 50
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=100000 type=sun use_max=true ans_exist=true 1111229" "tests\51" 51
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=500 type=sun use_max=true ans_exist=false 11112271" "tests\52" 52
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=100 type=sun use_max=true ans_exist=false 11112272" "tests\53" 53
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=10 type=sun use_max=true ans_exist=false 11112273" "tests\54" 54
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111321" "tests\55" 55
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111322" "tests\56" 56
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111323" "tests\57" 57
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111324" "tests\58" 58
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111325" "tests\59" 59
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111326" "tests\60" 60
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111327" "tests\61" 61
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=false 12217732" "tests\62" 62
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=50 type=random2 use_max=true ans_exist=false 12317732" "tests\63" 63
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=2 type=random2 use_max=true ans_exist=false 12417732" "tests\64" 64
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=100000 type=random2 use_max=true ans_exist=false 12517732" "tests\65" 65
call scripts\gen-input-via-stdout.bat "java.exe -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files\Equidistant_gen.jar max_n=200000 max_m=200000 type=random2 use_max=false ans_exist=false 12617732" "tests\66" 66
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
call scripts\gen-answer.bat tests\42 tests\42.a "tests" ""
call scripts\gen-answer.bat tests\43 tests\43.a "tests" ""
call scripts\gen-answer.bat tests\44 tests\44.a "tests" ""
call scripts\gen-answer.bat tests\45 tests\45.a "tests" ""
call scripts\gen-answer.bat tests\46 tests\46.a "tests" ""
call scripts\gen-answer.bat tests\47 tests\47.a "tests" ""
call scripts\gen-answer.bat tests\48 tests\48.a "tests" ""
call scripts\gen-answer.bat tests\49 tests\49.a "tests" ""
call scripts\gen-answer.bat tests\50 tests\50.a "tests" ""
call scripts\gen-answer.bat tests\51 tests\51.a "tests" ""
call scripts\gen-answer.bat tests\52 tests\52.a "tests" ""
call scripts\gen-answer.bat tests\53 tests\53.a "tests" ""
call scripts\gen-answer.bat tests\54 tests\54.a "tests" ""
call scripts\gen-answer.bat tests\55 tests\55.a "tests" ""
call scripts\gen-answer.bat tests\56 tests\56.a "tests" ""
call scripts\gen-answer.bat tests\57 tests\57.a "tests" ""
call scripts\gen-answer.bat tests\58 tests\58.a "tests" ""
call scripts\gen-answer.bat tests\59 tests\59.a "tests" ""
call scripts\gen-answer.bat tests\60 tests\60.a "tests" ""
call scripts\gen-answer.bat tests\61 tests\61.a "tests" ""
call scripts\gen-answer.bat tests\62 tests\62.a "tests" ""
call scripts\gen-answer.bat tests\63 tests\63.a "tests" ""
call scripts\gen-answer.bat tests\64 tests\64.a "tests" ""
call scripts\gen-answer.bat tests\65 tests\65.a "tests" ""
call scripts\gen-answer.bat tests\66 tests\66.a "tests" ""
call scripts\gen-answer.bat tests\67 tests\67.a "tests" ""

