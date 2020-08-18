import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class jeroen {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static int n, p;
	static int[] l, r, x;

	public static void main(String[] args) throws Exception {
		// Read input
		n = Integer.valueOf(in.readLine());
		l = new int[n];
		r = new int[n];
		for(int i = 0; i < n; i++) {
			String[] ps = in.readLine().split(" ");
			l[i] = Integer.valueOf(ps[0]);
			r[i] = Integer.valueOf(ps[1]);
		}
		p = Integer.valueOf(in.readLine());
		String[] ps = in.readLine().split(" ");
		x = new int[p];
		for(int i = 0; i < p; i++)
			x[i] = Integer.valueOf(ps[i]);

		// Count the number of existing pegs for each
		// canvas
		int ci = 0;
		int pi = 0;
		int[] cnt = new int[n];
		boolean[] onBegin = new boolean[n];
		while(pi < p) {
			while(ci < n - 1 && x[pi] > r[ci]) ci++;
			if(l[ci] <= x[pi] && x[pi] <= r[ci]) cnt[ci]++;
			if(ci < n - 1 && x[pi] == l[ci+1]) {
				cnt[ci+1]++;
				onBegin[ci+1] = true;
			}
			pi++;
		}

		// If there are already more than two pegs at a location, we're doomed
		for(int i = 0; i < n; i++) {
			if(cnt[i] > 2) {
				System.out.println("impossible");
				return;
			}
		}

		// Now add pegs greedily. We prefer overlapping with
		// the next canvas if possible, otherwise we just pick some
		// location.
		ArrayList<Integer> pegs = new ArrayList<Integer>();
		HashSet<Integer> existingPegs = new HashSet<Integer>();
		for(int i = 0; i < p; i++) existingPegs.add(x[i]);
		for(int i = 0; i < n; i++) {
			// Loop over the amount of pegs we still need
			for(int j = 0; j < 2 - cnt[i]; j++) {
				// Can we place one on the next overlap?
				if(i < n - 1 && r[i] == l[i+1] && cnt[i+1] < 2 && !onBegin[i+1]) {
					pegs.add(r[i]);
					existingPegs.add(r[i]);
					cnt[i+1]++;
					onBegin[i+1] = true;
				} else {
					// Find a free spot
					int px = l[i];
					if(i > 0 && r[i-1] == l[i]) px++;
					while(px <= r[i] && existingPegs.contains(px))
						px++;
					if(px > r[i]) {
						// No free spot :(
						System.out.println("impossible");
						return;
					}
					pegs.add(px);
					existingPegs.add(px);
				}
			}
		}

		// Print the output
		System.out.println(pegs.size());
		for(int p : pegs)
			System.out.print(p + " ");
		System.out.println();
	}
}
