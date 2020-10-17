#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir -p tests
echo "Generating test #3"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=10 max_m=10 type=random ans_exist=true 1111" "tests/03" 3
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=20 max_m=20 type=random ans_exist=true 112" "tests/04" 4
echo "Generating test #5"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=30 max_m=30 type=random ans_exist=true 1122" "tests/05" 5
echo "Generating test #6"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=40 max_m=40 type=random ans_exist=true 1124" "tests/06" 6
echo "Generating test #7"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=50 max_m=50 type=random ans_exist=true 1126" "tests/07" 7
echo "Generating test #8"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=50 max_m=50 type=random ans_exist=false 11265" "tests/08" 8
echo "Generating test #9"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=100000 max_m=100000 type=random ans_exist=true 11442" "tests/09" 9
echo "Generating test #10"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=200000 type=random ans_exist=true 114424" "tests/10" 10
echo "Generating test #11"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=100000 type=random ans_exist=true 114442" "tests/11" 11
echo "Generating test #12"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=200000 type=random ans_exist=true 1144421" "tests/12" 12
echo "Generating test #13"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=200000 type=random ans_exist=true 1144422" "tests/13" 13
echo "Generating test #14"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=200000 type=random ans_exist=true 1144423" "tests/14" 14
echo "Generating test #15"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=50000 type=spec1 use_max=true ans_exist=true 11111" "tests/15" 15
echo "Generating test #16"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=10000 type=spec1 use_max=true ans_exist=true 11112" "tests/16" 16
echo "Generating test #17"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=20000 type=spec1 use_max=true ans_exist=true 11113" "tests/17" 17
echo "Generating test #18"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=100 type=spec1 use_max=true ans_exist=true 11114" "tests/18" 18
echo "Generating test #19"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=100000 type=spec1 use_max=true ans_exist=true 11153" "tests/19" 19
echo "Generating test #20"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=190000 type=spec1 use_max=true ans_exist=true 11164" "tests/20" 20
echo "Generating test #21"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=190000 type=spec1 use_max=true ans_exist=false 111642" "tests/21" 21
echo "Generating test #22"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=10000 type=spec1 use_max=true ans_exist=false 111644" "tests/22" 22
echo "Generating test #23"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=50000 type=spec1 use_max=true ans_exist=false 111645" "tests/23" 23
echo "Generating test #24"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=100000 type=spec1 use_max=true ans_exist=false 111646" "tests/24" 24
echo "Generating test #25"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=2 type=one_line use_max=true 1231" "tests/25" 25
echo "Generating test #26"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=3 type=one_line use_max=true 1232" "tests/26" 26
echo "Generating test #27"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=5 type=one_line use_max=true 1233" "tests/27" 27
echo "Generating test #28"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=1000 type=one_line use_max=true 1234" "tests/28" 28
echo "Generating test #29"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=200000 type=one_line use_max=true 1235" "tests/29" 29
echo "Generating test #30"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=199000 type=one_line use_max=true 1236" "tests/30" 30
echo "Generating test #31"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 type=full_binary use_max=true ans_exist=true 234324" "tests/31" 31
echo "Generating test #32"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 type=full_binary use_max=true ans_exist=true 2343241" "tests/32" 32
echo "Generating test #33"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 type=full_binary use_max=true ans_exist=true 2343242" "tests/33" 33
echo "Generating test #34"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=3 type=full_binary use_max=true ans_exist=false 23432" "tests/34" 34
echo "Generating test #35"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=4 type=full_binary use_max=true ans_exist=false 234321" "tests/35" 35
echo "Generating test #36"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=5 type=full_binary use_max=true ans_exist=false 234322" "tests/36" 36
echo "Generating test #37"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=10 type=full_binary use_max=true ans_exist=false 234323" "tests/37" 37
echo "Generating test #38"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=20 type=full_binary use_max=true ans_exist=false 234324" "tests/38" 38
echo "Generating test #39"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=50 type=full_binary use_max=true ans_exist=false 234325" "tests/39" 39
echo "Generating test #40"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=1000 type=full_binary use_max=true ans_exist=false 234326" "tests/40" 40
echo "Generating test #41"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=100000 type=full_binary use_max=true ans_exist=false 234326" "tests/41" 41
echo "Generating test #42"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=200000 type=full_binary use_max=true ans_exist=false 234326" "tests/42" 42
echo "Generating test #43"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=3 type=sun use_max=true ans_exist=true 1111221" "tests/43" 43
echo "Generating test #44"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=4 type=sun use_max=true ans_exist=true 1111222" "tests/44" 44
echo "Generating test #45"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=5 type=sun use_max=true ans_exist=true 1111223" "tests/45" 45
echo "Generating test #46"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=10 type=sun use_max=true ans_exist=true 1111224" "tests/46" 46
echo "Generating test #47"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=50 type=sun use_max=true ans_exist=true 1111225" "tests/47" 47
echo "Generating test #48"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=150 type=sun use_max=true ans_exist=true 1111226" "tests/48" 48
echo "Generating test #49"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=500 type=sun use_max=true ans_exist=true 1111227" "tests/49" 49
echo "Generating test #50"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=10000 type=sun use_max=true ans_exist=true 1111228" "tests/50" 50
echo "Generating test #51"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=100000 type=sun use_max=true ans_exist=true 1111229" "tests/51" 51
echo "Generating test #52"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=500 type=sun use_max=true ans_exist=false 11112271" "tests/52" 52
echo "Generating test #53"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=100 type=sun use_max=true ans_exist=false 11112272" "tests/53" 53
echo "Generating test #54"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=10 type=sun use_max=true ans_exist=false 11112273" "tests/54" 54
echo "Generating test #55"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111321" "tests/55" 55
echo "Generating test #56"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111322" "tests/56" 56
echo "Generating test #57"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111323" "tests/57" 57
echo "Generating test #58"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111324" "tests/58" 58
echo "Generating test #59"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111325" "tests/59" 59
echo "Generating test #60"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111326" "tests/60" 60
echo "Generating test #61"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=true 12111327" "tests/61" 61
echo "Generating test #62"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=500 type=random2 use_max=true ans_exist=false 12217732" "tests/62" 62
echo "Generating test #63"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=50 type=random2 use_max=true ans_exist=false 12317732" "tests/63" 63
echo "Generating test #64"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=2 type=random2 use_max=true ans_exist=false 12417732" "tests/64" 64
echo "Generating test #65"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=100000 type=random2 use_max=true ans_exist=false 12517732" "tests/65" 65
echo "Generating test #66"
scripts/gen-input-via-stdout.sh "java -Xmx512M -Xss64M -DONLINE_JUDGE=true -Duser.language=en -Duser.region=US -Duser.variant=US -jar files/Equidistant_gen.jar max_n=200000 max_m=200000 type=random2 use_max=false ans_exist=false 12617732" "tests/66" 66
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
echo "Generating answer for test #10"
scripts/gen-answer.sh tests/10 tests/10.a "tests" ""
echo ""
echo "Generating answer for test #11"
scripts/gen-answer.sh tests/11 tests/11.a "tests" ""
echo ""
echo "Generating answer for test #12"
scripts/gen-answer.sh tests/12 tests/12.a "tests" ""
echo ""
echo "Generating answer for test #13"
scripts/gen-answer.sh tests/13 tests/13.a "tests" ""
echo ""
echo "Generating answer for test #14"
scripts/gen-answer.sh tests/14 tests/14.a "tests" ""
echo ""
echo "Generating answer for test #15"
scripts/gen-answer.sh tests/15 tests/15.a "tests" ""
echo ""
echo "Generating answer for test #16"
scripts/gen-answer.sh tests/16 tests/16.a "tests" ""
echo ""
echo "Generating answer for test #17"
scripts/gen-answer.sh tests/17 tests/17.a "tests" ""
echo ""
echo "Generating answer for test #18"
scripts/gen-answer.sh tests/18 tests/18.a "tests" ""
echo ""
echo "Generating answer for test #19"
scripts/gen-answer.sh tests/19 tests/19.a "tests" ""
echo ""
echo "Generating answer for test #20"
scripts/gen-answer.sh tests/20 tests/20.a "tests" ""
echo ""
echo "Generating answer for test #21"
scripts/gen-answer.sh tests/21 tests/21.a "tests" ""
echo ""
echo "Generating answer for test #22"
scripts/gen-answer.sh tests/22 tests/22.a "tests" ""
echo ""
echo "Generating answer for test #23"
scripts/gen-answer.sh tests/23 tests/23.a "tests" ""
echo ""
echo "Generating answer for test #24"
scripts/gen-answer.sh tests/24 tests/24.a "tests" ""
echo ""
echo "Generating answer for test #25"
scripts/gen-answer.sh tests/25 tests/25.a "tests" ""
echo ""
echo "Generating answer for test #26"
scripts/gen-answer.sh tests/26 tests/26.a "tests" ""
echo ""
echo "Generating answer for test #27"
scripts/gen-answer.sh tests/27 tests/27.a "tests" ""
echo ""
echo "Generating answer for test #28"
scripts/gen-answer.sh tests/28 tests/28.a "tests" ""
echo ""
echo "Generating answer for test #29"
scripts/gen-answer.sh tests/29 tests/29.a "tests" ""
echo ""
echo "Generating answer for test #30"
scripts/gen-answer.sh tests/30 tests/30.a "tests" ""
echo ""
echo "Generating answer for test #31"
scripts/gen-answer.sh tests/31 tests/31.a "tests" ""
echo ""
echo "Generating answer for test #32"
scripts/gen-answer.sh tests/32 tests/32.a "tests" ""
echo ""
echo "Generating answer for test #33"
scripts/gen-answer.sh tests/33 tests/33.a "tests" ""
echo ""
echo "Generating answer for test #34"
scripts/gen-answer.sh tests/34 tests/34.a "tests" ""
echo ""
echo "Generating answer for test #35"
scripts/gen-answer.sh tests/35 tests/35.a "tests" ""
echo ""
echo "Generating answer for test #36"
scripts/gen-answer.sh tests/36 tests/36.a "tests" ""
echo ""
echo "Generating answer for test #37"
scripts/gen-answer.sh tests/37 tests/37.a "tests" ""
echo ""
echo "Generating answer for test #38"
scripts/gen-answer.sh tests/38 tests/38.a "tests" ""
echo ""
echo "Generating answer for test #39"
scripts/gen-answer.sh tests/39 tests/39.a "tests" ""
echo ""
echo "Generating answer for test #40"
scripts/gen-answer.sh tests/40 tests/40.a "tests" ""
echo ""
echo "Generating answer for test #41"
scripts/gen-answer.sh tests/41 tests/41.a "tests" ""
echo ""
echo "Generating answer for test #42"
scripts/gen-answer.sh tests/42 tests/42.a "tests" ""
echo ""
echo "Generating answer for test #43"
scripts/gen-answer.sh tests/43 tests/43.a "tests" ""
echo ""
echo "Generating answer for test #44"
scripts/gen-answer.sh tests/44 tests/44.a "tests" ""
echo ""
echo "Generating answer for test #45"
scripts/gen-answer.sh tests/45 tests/45.a "tests" ""
echo ""
echo "Generating answer for test #46"
scripts/gen-answer.sh tests/46 tests/46.a "tests" ""
echo ""
echo "Generating answer for test #47"
scripts/gen-answer.sh tests/47 tests/47.a "tests" ""
echo ""
echo "Generating answer for test #48"
scripts/gen-answer.sh tests/48 tests/48.a "tests" ""
echo ""
echo "Generating answer for test #49"
scripts/gen-answer.sh tests/49 tests/49.a "tests" ""
echo ""
echo "Generating answer for test #50"
scripts/gen-answer.sh tests/50 tests/50.a "tests" ""
echo ""
echo "Generating answer for test #51"
scripts/gen-answer.sh tests/51 tests/51.a "tests" ""
echo ""
echo "Generating answer for test #52"
scripts/gen-answer.sh tests/52 tests/52.a "tests" ""
echo ""
echo "Generating answer for test #53"
scripts/gen-answer.sh tests/53 tests/53.a "tests" ""
echo ""
echo "Generating answer for test #54"
scripts/gen-answer.sh tests/54 tests/54.a "tests" ""
echo ""
echo "Generating answer for test #55"
scripts/gen-answer.sh tests/55 tests/55.a "tests" ""
echo ""
echo "Generating answer for test #56"
scripts/gen-answer.sh tests/56 tests/56.a "tests" ""
echo ""
echo "Generating answer for test #57"
scripts/gen-answer.sh tests/57 tests/57.a "tests" ""
echo ""
echo "Generating answer for test #58"
scripts/gen-answer.sh tests/58 tests/58.a "tests" ""
echo ""
echo "Generating answer for test #59"
scripts/gen-answer.sh tests/59 tests/59.a "tests" ""
echo ""
echo "Generating answer for test #60"
scripts/gen-answer.sh tests/60 tests/60.a "tests" ""
echo ""
echo "Generating answer for test #61"
scripts/gen-answer.sh tests/61 tests/61.a "tests" ""
echo ""
echo "Generating answer for test #62"
scripts/gen-answer.sh tests/62 tests/62.a "tests" ""
echo ""
echo "Generating answer for test #63"
scripts/gen-answer.sh tests/63 tests/63.a "tests" ""
echo ""
echo "Generating answer for test #64"
scripts/gen-answer.sh tests/64 tests/64.a "tests" ""
echo ""
echo "Generating answer for test #65"
scripts/gen-answer.sh tests/65 tests/65.a "tests" ""
echo ""
echo "Generating answer for test #66"
scripts/gen-answer.sh tests/66 tests/66.a "tests" ""
echo ""
echo "Generating answer for test #67"
scripts/gen-answer.sh tests/67 tests/67.a "tests" ""
echo ""

