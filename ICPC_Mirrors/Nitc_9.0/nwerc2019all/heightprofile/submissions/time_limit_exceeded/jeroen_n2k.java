// O(n^2 k)
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class jeroen_n2k {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		// Read input
		String[] ps = in.readLine().split(" ");
		int n = Integer.valueOf(ps[0]) + 1;
		int k = Integer.valueOf(ps[1]);
		long[] h = new long[n];
		ps = in.readLine().split(" ");
		for(int i = 0; i < n; i++)
			h[i] = Integer.valueOf(ps[i]);

		// Solve for each k independently
		for(int i = 0; i < k; i++) {
			int incline = (int)Math.round(Double.valueOf(in.readLine()) * 10);

			// Let's rotate the mountain so that we can look at an incline
			// rate of 0.
			long[] h2 = new long[n];
			for(int j = 0; j < n; j++) {
				h2[j] = h[j] - incline * j;
			}

			// Now we want the longest segment x - y where h2[x] <= h2[y]
			ArrayList<Long> valleys = new ArrayList<Long>();
			ArrayList<Integer> valleysidx = new ArrayList<Integer>();
			valleys.add(h2[0]);
			valleysidx.add(0);
			double best = 0;
			for(int j = 1; j < n; j++) {
				// What is the longest segment that could end here?
				int m = valleys.size();
				int g = m;
				while(g > 0 && valleys.get(g-1) <= h2[j]) g--;
				if(g < m) {
					// We've found at least this length
					g = valleysidx.get(g);
					int ilen = j - g;
					best = Math.max(best, ilen);

					// Maybe we can extend a bit to the left
					if(g > 0)
						best = Math.max(best, ilen + Math.min(1, 1 - (double)(h2[g-1] - h2[j]) / (h2[g-1] - h2[g])));

					// Or to the right
					if(j < n - 1 && h2[j+1] < h2[j])
						best = Math.max(best, ilen + Math.min(1, (double)(h2[j] - h2[g]) / (h2[j] - h2[j+1])));
				}
				// Add this as a new deepest point?
				if(h2[j] < valleys.get(m-1)) {
					valleys.add(h2[j]);
					valleysidx.add(j);
				}
			}

			System.out.println(best == 0 ? "impossible" : String.valueOf(best));
		}
	}
}
