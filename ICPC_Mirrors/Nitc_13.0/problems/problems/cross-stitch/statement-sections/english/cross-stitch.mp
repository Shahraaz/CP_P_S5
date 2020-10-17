prologues := 3; % make it work with ps2pdf
outputtemplate := "%j-%c.ps"; % better file names
input TEX
input rboxes;

u := 10mm;
d := 0.2;
dr := 30;

beginfig(1)
    w := 3;
    h := 2;

    pickup pencircle scaled 0.5pt;
    for i := 0 upto w:
        draw ((i, -d)--(i, h + d)) scaled u;
        label.top(decimal(i), (i, h + d) scaled u);
    endfor

    for i := 0 upto h:
        draw ((-d, h - i)--(w + d, h - i)) scaled u;
        label.lft(decimal(i), (-d, h - i) scaled u);
    endfor

    ahangle := 20;
    ahlength := u / 3;
    ahvariant := 2;
    ahdimple := 0.5;
    linecap := butt;
%    linecap := squared;

    pickup pencircle scaled 2pt;

    drawarrow ((1, h - 1)--(2, h - 0)) scaled u;
    drawarrow ((2, h - 0)--(2, h - 1)) scaled u dashed evenly;
    drawarrow ((2, h - 1)--(3, h - 0)) scaled u;
    drawarrow ((3, h - 0)--(2, h - 0)) scaled u dashed evenly;
    drawarrow ((2, h - 0)--(3, h - 1)) scaled u;
    drawarrow ((3, h - 1)..(2, h - 1){dir 150}) scaled u dashed evenly;
    drawarrow ((2, h - 1)--(3, h - 2)) scaled u;
    drawarrow ((3, h - 2)--(2, h - 2)) scaled u dashed evenly;
    drawarrow ((2, h - 2)--(3, h - 1)) scaled u;
    drawarrow ((3, h - 1)..(2, h - 1){dir 210}) scaled u dashed evenly;
    drawarrow ((2, h - 1)--(1, h - 0)) scaled u;
endfig;


beginfig(2)
    u := 1.5cm;
    pickup pencircle scaled 1.5pt;

    drawarrow ((0, 0)--(1, 1)) scaled u;
    drawarrow ((1, 1)--(1, 0)) scaled u dashed evenly;
    drawarrow ((1, 0)--(0, 1)) scaled u;
    drawarrow ((0, 1)--(0, 0)) scaled u dashed evenly;
endfig;

end.
