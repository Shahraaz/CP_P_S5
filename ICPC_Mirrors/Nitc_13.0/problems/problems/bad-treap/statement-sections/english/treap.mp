prologues := 3; % make it work with ps2pdf
outputtemplate := "%j-%c.ps"; % better file names
input TEX
input rboxes;

ux := 1cm;
uy := 1cm;

def v(expr x, y, px, py, shifty) =
	save a;
	rboxit.a(TEX("$(" & decimal(x) & ", " & decimal(y) & ")$"));
	a.c = (x * ux, (y + shifty) * uy);
	drawboxed(a);
	if x <> px:
		save b;
		rboxit.b(TEX("$(" & decimal(px) & ", " & decimal(py) & ")$"));
		b.c = (px * ux, py * uy);
		draw a.c -- b.c cutbefore bpath.a cutafter bpath.b;
	fi;
enddef;

beginfig(1)
	v(5, 9.2, 5, 9.2, 0);
	v(1, 8.4, 5, 9.2, 0);
	v(4, 7.8, 1, 8.4, 0);
	v(2, 7.1, 4, 7.8, 0);
	v(7, 8.8, 5, 9.2, 0);
	v(6, 7.5, 7, 8.8, 0);
	v(8, 6.8, 7, 8.8, 0);
endfig;

beginfig(2)
	s4 := 0.7568;%0.7568024953079282;
	s2 := -0.9093;%-0.9092974268256817;
	s1 := -0.8415;%-0.8414709848078965;
	v(-4, s4, -4, s4, 0);
	v(0, 0, -4, s4, 0);
	v(-1, s1, 0, 0, 0);
	v(-2, s2, -1, s1, -0.8);
endfig;

end.
