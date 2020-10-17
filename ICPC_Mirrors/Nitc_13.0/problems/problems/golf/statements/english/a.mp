prologues := 3; % make it work with ps2pdf
outputtemplate := "%j-%c.ps"; % better file names

u := 5mm;
v := 0.5mm;

beginfig(1)

pickup pencircle scaled 1pt;

draw (0u,0u)--(10u,0u);
draw (0u,8u)--(10u,8u);
draw (0u,0u)--(0u,8u);
draw (10u,0u)--(10u,8u);

pickup pencircle scaled 0.5pt;

draw (0u,1u)--(10u,1u);
draw (0u,2u)--(10u,2u);
draw (0u,3u)--(10u,3u);
draw (0u,4u)--(10u,4u);
draw (0u,5u)--(10u,5u);
draw (0u,6u)--(10u,6u);
draw (0u,7u)--(10u,7u);

draw (1u,0u)--(1u,8u);
draw (2u,0u)--(2u,8u);
draw (3u,0u)--(3u,8u);
draw (4u,0u)--(4u,8u);
draw (5u,0u)--(5u,8u);
draw (6u,0u)--(6u,8u);
draw (7u,0u)--(7u,8u);
draw (8u,0u)--(8u,8u);
draw (9u,0u)--(9u,8u);

drawarrow (10u, 0u)--(11u, 0u);
label.lrt("x", (11u, 0u));

drawarrow (0u, 8u)--(0u, 9u);
label.ulft("y", (0u, 9u));

label.llft("0", (0u, 0u));

pickup pencircle scaled 3pt;

draw (1u,4u)--(1u,5u)--(3u,5u)--(3u,6u)--(4u,6u)--(4u,4u)--(1u,4u);

pickup pencircle scaled 6pt;

draw (2u,2u);
draw (1u,7u);
draw (4u,7u);
draw (7u,5u+v);
%draw (1u,6u);

pickup pencircle scaled 1pt;

label.ulft("1", (2u, 2u));
drawarrow (2u,2u)--(3u,3u);
draw (3u,3u)--(4u,4u);

label.ulft("2", (1u, 7u));
drawarrow (1u,7u)--(2u,8u);
draw (2u,8u)--(4u,6u);

label.ulft("3", (4u, 7u));
drawarrow (4u,7u)--(5u,8u);
draw (5u,8u)--(10u,3u)--(7u,0u)--(3u,4u);

label.ulft("4", (7u, 5u+v));
drawarrow (7u,5u+v)--(8u,6u+v);
draw (8u,6u+v)--(10u-v,8u)--(10u,8u-v)--(2u,0u)--(0u,2u)--(2u,4u);

%label.ulft("5", (1u, 6u));
%drawarrow (1u,6u)--(2u,7u);
%draw (2u,7u)--(3u,8u)--(10u,1u)--(9u,0u)--(4u,5u);

endfig;

beginfig(2)

pickup pencircle scaled 1pt;

draw (0u,0u)--(6u,0u);
draw (0u,6u)--(6u,6u);
draw (0u,0u)--(0u,6u);
draw (6u,0u)--(6u,6u);

pickup pencircle scaled 0.5pt;

draw (0u,1u)--(6u,1u);
draw (0u,2u)--(6u,2u);
draw (0u,3u)--(6u,3u);
draw (0u,4u)--(6u,4u);
draw (0u,5u)--(6u,5u);

draw (1u,0u)--(1u,6u);
draw (2u,0u)--(2u,6u);
draw (3u,0u)--(3u,6u);
draw (4u,0u)--(4u,6u);
draw (5u,0u)--(5u,6u);

drawarrow (6u, 0u)--(7u, 0u);
label.lrt("x", (7u, 0u));

drawarrow (0u, 6u)--(0u, 7u);
label.ulft("y", (0u, 7u));

label.llft("0", (0u, 0u));

pickup pencircle scaled 3pt;

draw (2u,2u)--(2u,4u)--(4u,4u)--(4u,2u)--(2u,2u);

pickup pencircle scaled 6pt;

%draw (5u,3u);
draw (5u,5u+v);
draw (5u,2u);

pickup pencircle scaled 1pt;

%label.ulft("1", (5u, 3u));
%label.llft("3", (5u, 3u));
%drawarrow (5u,3u)--(6u,4u);
%draw (6u,4u)--(4u,6u)--(2u,4u);

label.ulft("1", (5u, 5u+v));
label.lrt("3", (5u, 5u));
drawarrow (5u,5u+v)--(6u-v,6u);
draw (6u-v,6u)--(6u,6u-v)--(4u,4u);

label.ulft("2", (5u, 2u));
drawarrow (5u,2u)--(6u,3u);
draw (6u,3u)--(3u,6u)--(0u,3u)--(3u,0u)--(5u,2u);

endfig;

end.