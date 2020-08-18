// Usage: cat ../data/sample/2.{in,ans} | asy -nosafe ./sample.asy

import settings;
outformat="pdf";

defaultpen(0.25);
bbox(white, Fill);

pen[] colours = {
  orange,
  lightblue,
  red,
  fuchsia,
  green,
  purple,
};

int SCALE = 5;
real PSCALE = 2.5 * SCALE;

if (true) {
  int min_x = 0;
  int max_x = 0;

  // Read canvas positions.
  int n = stdin;
  path[] canvases = new path[];
  for (int i = 0; i < n; ++i) {
    int x0 = SCALE * (int) stdin;
    int x1 = SCALE * (int) stdin;
    real y0 = 0;
    real y1 = (x0 - x1) / (sqrt(5.0) - 1.0);

    canvases.push((x0, y0) -- (x1, y0) -- (x1, y1) ::{-0.8,-0.1}  (x0, y1) -- cycle);
    min_x = min(min_x, x0);
    max_x = max(max_x, x1 + 10);
  }

  // Draw ticks.
  for (int x = min_x; x <= max_x; x += SCALE) {
    if (x % (10 * SCALE) == 0) {
      draw((x, PSCALE/3) -- (x, 0), grey);
    } else {
      draw((x, PSCALE/8) -- (x, 0), grey);
    }
  }

  // Draw canvases.
  for (int i = 0; i < n; ++i) {
    fill(shift(0, -1.5) * canvases[i], grey);
  }
  for (int i = 0; i < n; ++i) {
    fill(                 canvases[i], colours[i % colours.length]);
  }

  // Draw clothesline.
  draw((min_x - SCALE/2, 0) -- (max_x + SCALE/2, 0));
}

real[] read_pegs() {
  if (eof(stdin)) {
    return new real[];
  }
  int n = stdin;
  real[] x = new real[n];
  for (int i = 0; i < n; ++i) {
    x[i] = ((real) stdin);
  }
  return x;
}

void add_pegs(real[] positions, pen fillpen, pen drawpen) {
  for (int i = 0; i < positions.length; ++i) {
    real x = SCALE * positions[i];
    real y = 0;
    path peg =
        (x - PSCALE/6, y - PSCALE/3) --
        (x - PSCALE/6, y - PSCALE/8) -- (x - PSCALE/10, y - PSCALE/8) --
        (x - PSCALE/10, y - PSCALE/12) -- (x - PSCALE/6, y - PSCALE/12) --
        (x - PSCALE/6, y + PSCALE/2) --
        (x + PSCALE/6, y + PSCALE/2) --
        (x + PSCALE/6, y - PSCALE/12) -- (x + PSCALE/10, y - PSCALE/12) --
        (x + PSCALE/10, y - PSCALE/8) -- (x + PSCALE/6, y - PSCALE/8) --
        (x + PSCALE/6, y - PSCALE/3) -- cycle;
    fill(shift(0, -0.75) * peg, darkgrey);
    filldraw(peg, fillpen=fillpen, drawpen=drawpen);
    filldraw(
        (x - PSCALE/10, y - PSCALE/12) --
        (x + PSCALE/10, y - PSCALE/12) --
        (x + PSCALE/10, y - PSCALE/8) --
        (x - PSCALE/10, y - PSCALE/8) -- cycle,
        fillpen=grey, drawpen=drawpen);
  }
}

add_pegs(read_pegs(), fillpen=white, drawpen=black);
add_pegs(read_pegs(), fillpen=blue, drawpen=black);

shipout();
