// O(n^2)
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class jeroen_overflow {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static int n;
	static int[] l, r;
	static int d, t;

	public static void main(String[] args) throws Exception {
		// Read input and convert it to the old input format
		String[] ps = in.readLine().split(" ");
		int s = Integer.valueOf(ps[0]);
		d = Integer.valueOf(ps[1]);
		t = Integer.valueOf(ps[2]);
		n = Integer.valueOf(in.readLine())+1;
		l = new int[n];
		r = new int[n];
		l[0] = 0;
		r[n-1] = s;
		for(int i = 0; i < n - 1; i++) {
			ps = in.readLine().split(" ");
			r[i] = Integer.valueOf(ps[0]);
			l[i+1] = Integer.valueOf(ps[1]);
		}

		// We can assume a jump always starts or ends at the extreme point
		// of an island. If we have an optimal solution which would not satisfy
		// this property, we can move the jump interval to the right until the
		// start or end of the jump is at the rightmost point of an island.
		// We thus only need to consider the following points as being
		// interesting.
		TreeSet<Integer> spts = new TreeSet<Integer>();
		for(int i = 0; i < n; i++) {
			spts.add(l[i]);
			spts.add(r[i]);
			if(onIsland(l[i] - d) != -1)
				spts.add(l[i] - d);
			if(onIsland(l[i] + d) != -1)
				spts.add(l[i] + d);
			if(onIsland(r[i] - d) != -1)
				spts.add(r[i] - d);
			if(onIsland(r[i] + d) != -1)
				spts.add(r[i] + d);
		}
		int m = spts.size(); // m is in O(n)
		Integer[] pts = spts.toArray(new Integer[m]);
		int[] onisland = new int[m];
		for(int i = 0; i < m; i++)
			onisland[i] = onIsland(pts[i]);

		// Now we can run a dp over these interesting points
		int[] dp = new int[m];
		dp[0] = 0;
		for(int i = 1; i < m; i++) {
			dp[i] = Integer.MAX_VALUE;

			// Look back at all points we could have walked or jumped from
			int j = i - 1;
			while(j >= 0 && (pts[i] - pts[j] <= d || onisland[j] == onisland[i])) {
				// Could we have walked?
				if(onisland[j] == onisland[i])
					dp[i] = Math.min(dp[i], dp[j] + walkingDist(pts[i] - pts[j]));

				// Could we have jumped?
				if(pts[i] - pts[j] <= d)
					dp[i] = Math.min(dp[i], dp[j] + t);

				j--;
			}
		}
		System.out.println(dp[m-1]);
	}

	// Check on which island a point falls
	// O(n), but could easily be done in
	// O(log n)
	public static int onIsland(int x) {
		for(int i = 0; i < n; i++)
			if(l[i] <= x && x <= r[i])
				return i;
		return -1;
	}

	// How much time does it cost to walk this distance?
	// This could actually include jumping on the same island
	public static int walkingDist(int x) {
		if(t < d) {
			// Jumping can be fast than walking, so let's do that
			// a few times.
			int ret = t * (x / d); // Integer division, x/d whole jumps
			ret += Math.min(t, x % d); // for the last bit, walk or jump
			return ret;
		}
		return x;
	}
}

