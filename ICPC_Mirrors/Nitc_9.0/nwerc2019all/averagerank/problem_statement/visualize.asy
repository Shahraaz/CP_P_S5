import graph;
import bsp;
settings.tex="pdflatex";
texpreamble("\usepackage{times}");
defaultpen(2);

size(1000, 500);

int n = stdin;
int w = stdin;

// Constants
real spread = 0.15;
real yscale = 0.3;
real radius = 0.1;
real labelfontsize = 20;
pen labelpen = fontsize(labelfontsize);

// Everybody has score 0 at time 0
pair[][] scores = array(n, new pair[] {(0.0,0.0)});

if( n <= 100 && w <= 100){

	real maxscore = 0;

	for(int t = 0; t < w; ++t){
		int k = stdin;
		for(int j = 0; j < k; ++j){
			int p = stdin;
			real prevscore = scores[p-1][scores[p-1].length-1].y;
			scores[p-1].push((t, prevscore));
			scores[p-1].push((t+1, prevscore + 1));
			maxscore = max(maxscore,  prevscore + 1);
		}
	}

	for(int p = 0; p < n; ++p){
		real lastscore = scores[p][scores[p].length-1].y;
		scores[p].push((w, lastscore));
	}

	for(int t = 0; t <= w; ++t){
		draw((t, -.2) -- (t, yscale*maxscore+0.2), linewidth(1) + grey);
	}

	// Draw all graphs
	int[] colors = {3, 9, 0, 14, 1};
	int[] ranks = {4, 2, 0, 3, 1};
	for(int p = 0; p < n; ++p){
		real offset = spread /n * ranks[p];
		for(int i = 0; i < scores[p].length-1; ++i){
			if(ranks[p] == 4 && i == 2){
				offset = spread / n * (ranks[p]-1.5);
			}
			real offset2 = offset;
			if(ranks[p] == 4 && i == 1){
				offset2 = spread / n * (ranks[p]-1.5);
			}
			pair p1 = (scores[p][i].x, yscale*scores[p][i].y-offset);
			pair p2 = (scores[p][i+1].x, yscale*scores[p][i+1].y-offset2);
			path pa = p1 -- p2;
			draw(pa , colorPen[colors[p]]);

			// Balloon for every problem solved.
			if(p2.y > p1.y){
				if(p == 4 && p1.x == 0){
					// South align one balloon.
					//label(graphic("balloon.png", "width=0.95cm"), (p1+2*p2)/3, align=S);
					label(scale(1.2)*"$+1$", (p1+2*p2)/3, align=SE);
				} else {
					//label(graphic("balloon.png", "width=0.95cm"), (2*p1+p2)/3, align=N);
					label(scale(1.2)*"$+1$", (2*p1+p2)/3, align=NW);
				}
			}
		}
	}
}

label("Rank 1: competitor 3", (6.1, 4*yscale), labelpen, align=E);
label("Rank 2: competitor 5", (6.1, 3*yscale-spread/5*1), labelpen, align=E);
label("Rank 3: competitor 2, 4 ", (6.1, 2*yscale-spread/5*2), labelpen, align=E);
label("Rank 5: competitor 1", (6.1, 1*yscale-spread/5*3), labelpen, align=E);
real points_x = 8;
label("(4 points)", (points_x, 4*yscale), labelpen, align=E);
label("(3 points)", (points_x, 3*yscale-spread/5*1), labelpen, align=E);
label("(2 points) ", (points_x, 2*yscale-spread/5*2), labelpen, align=E);
label("(1 point)", (points_x, 1*yscale-spread/5*3), labelpen, align=E);

// White background.
shipout(bbox(xmargin=5, white, Fill));
