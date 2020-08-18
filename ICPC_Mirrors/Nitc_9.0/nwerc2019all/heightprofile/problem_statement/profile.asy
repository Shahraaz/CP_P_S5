import graph;
texpreamble("\usepackage{times}");

unitsize(x=2.2cm, y=0.05cm);

xlimits(0, 8);
ylimits(0, 80);
yaxis("height (m)" , LeftRight(), RightTicks(ptick=lightgrey, extend=true));
xaxis("distance (km)", BottomTop(), LeftTicks(ptick=lightgrey, extend=true));

path p = (0, 0) -- (1, 0) -- (2, 10) -- (3, 30) -- (4, 60) -- (5, 45) -- (6, 75) -- (7, 65) -- (8, 30);

pen incline_pen = linewidth(2) + red;
pen decline_pen = linewidth(2) + green;
pen normal = linewidth(2) + yellow;
for (int i = 0; i < length(p); ++i) {
  real rise = ypart(point(p, i + 1) - point(p, i));
  real ratio = rise / 50.0;
  pen grade_pen = ratio > 0 ? incline_pen * ratio + normal * (1 - ratio)
                            : decline_pen * -ratio + normal * (1 + ratio);
  if (i == 2) {
    draw(Label(graphic("bike.eps", "width=0.95cm"), Relative(0.46), Rotate(dir(p, i, i + 1)), align=N),
         subpath(p, i , i + 1), grade_pen);
  } else {
    draw(subpath(p, i , i + 1), grade_pen);
  }
}
