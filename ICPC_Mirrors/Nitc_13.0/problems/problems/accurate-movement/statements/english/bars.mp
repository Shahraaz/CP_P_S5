prologues := 3; % make it work with ps2pdf
outputtemplate := "%j-%c.ps"; % better file names
input TEX
input rboxes;

u := 5mm;

def bar(expr l, x, y) =

    path box;
    box := ((0, 0)--(l, 0)--(l, 1)--(0, 1)--cycle) shifted (x, y) scaled u;

    pickup pencircle scaled 0.5pt;
    fill box withcolor 0.75 white;
    draw box;
enddef;


def barA(expr l, x) =
    bar(l, x, 1);
    draw ((0, 1)--(0, 0.7)) shifted (x, 0) scaled u;
    draw ((l, 1)--(l, 0.7)) shifted (x, 0) scaled u;
enddef;

def barB(expr l, x) =
    bar(l, x, 0);
enddef;

def fig(expr n, a, b, ax, bx) =
    for i := 0 upto n:
        draw ((i, -0.4)--(i, -0.2)) scaled u;
        label.bot(decimal(i), (i, -0.3) scaled u);
    endfor

    pickup pencircle scaled 1pt;
    draw ((0, 0.5)--(n, 0.5)) scaled u;
    draw ((0, 1.5)--(n, 1.5)) scaled u;
    barA(a, ax)
    barB(b, bx)

    pickup pencircle scaled 1pt;
    draw ((0, 0)--(0, 2)--(n, 2)--(n, 0)--cycle) scaled u;
enddef;

n := 6;
a := 3;
b := 1;

beginfig(1)
    fig(n, a, b, (n - a) / 2, (n - b) / 2);
endfig;

beginfig(2)
    fig(n, a, b, 0, 0);
endfig;

beginfig(3)
    fig(n, a, b, n - a, n - b);
endfig;

beginfig(4)
    fig(n, a, b, 0, 1.5);
endfig;

beginfig(5)
    fig(n, a, b, 1, 1.5);
endfig;

beginfig(6)
    fig(n, a, b, 1, 3);
endfig;

beginfig(7)
    fig(n, a, b, 3, 3);
endfig;

end.
