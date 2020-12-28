#!/bin/bash


for i in {1..1000}
do
    echo "Welcome $i times"
    cd /home/shahraaz/Documents/CP/CP_P_S5/ICPC_Mirrors/Nitc_22/
    echo $i > in2
    ./gen.out > in
    cd /home/shahraaz/projects/croupier
    python3 croupier.py "/home/shahraaz/Documents/CP/CP_P_S5/ICPC_Mirrors/Nitc_22/gen2.out" "/home/shahraaz/Documents/CP/CP_P_S5/ICPC_Mirrors/Nitc_22/i.out"
done