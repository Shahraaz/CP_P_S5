// O(n^2)
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class jeroen_n2 {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static int n;
	static long[] l, r;
	static long d, t;

	public static void main(String[] args) throws Exception {
		// Read input and convert it so that our intervals
		// are the water intervals instead of the islands.
		String[] ps = in.readLine().split(" ");
		long s = Long.valueOf(ps[0]);
		d = Long.valueOf(ps[1]);
		t = Long.valueOf(ps[2]);
		n = Integer.valueOf(in.readLine())+1;
		l = new long[n];
		r = new long[n];
		l[0] = 0;
		r[n-1] = s;
		for(int i = 0; i < n - 1; i++) {
			ps = in.readLine().split(" ");
			r[i] = Long.valueOf(ps[0]);
			l[i+1] = Long.valueOf(ps[1]);
		}

		// We can assume a jump always starts or ends at the extreme point
		// of water. If we have an optimal solution which would not satisfy
		// this property, we can move the jump interval to the right until the
		// start or end of the jump is at the rightmost point of water.
		// We thus only need to consider the following points as being
		// interesting.
		TreeSet<Long> spts = new TreeSet<Long>();
		for(int i = 0; i < n; i++) {
			spts.add(l[i]);
			spts.add(r[i]);
			if(onWater(l[i] - d) != -1)
				spts.add(l[i] - d);
			if(onWater(l[i] + d) != -1)
				spts.add(l[i] + d);
			if(onWater(r[i] - d) != -1)
				spts.add(r[i] - d);
			if(onWater(r[i] + d) != -1)
				spts.add(r[i] + d);
		}
		int m = spts.size(); // m is in O(n)
		Long[] pts = spts.toArray(new Long[m]);
		int[] onwater = new int[m];
		for(int i = 0; i < m; i++)
			onwater[i] = onWater(pts[i]);

		// Now we can run a dp over these interesting points
		long[] dp = new long[m];
		dp[0] = 0;
		for(int i = 1; i < m; i++) {
			dp[i] = Long.MAX_VALUE;

			// Look back at all points we could have walked or jumped from
			int j = i - 1;
			while(j >= 0 && (pts[i] - pts[j] <= d || onwater[j] == onwater[i])) {
				// Could we have walked?
				if(onwater[j] == onwater[i])
					dp[i] = Math.min(dp[i], dp[j] + walkingDist(pts[i] - pts[j]));

				// Could we have jumped?
				if(pts[i] - pts[j] <= d)
					dp[i] = Math.min(dp[i], dp[j] + t);

				j--;
			}
		}
		System.out.println(dp[m-1]);
	}

	// Check on which water a point falls
	// O(n), but could easily be done in
	// O(log n)
	public static int onWater(long x) {
		for(int i = 0; i < n; i++)
			if(l[i] <= x && x <= r[i])
				return i;
		return -1;
	}

	// How much time does it cost to walk this distance?
	// This could actually include jumping on the same island
	public static long walkingDist(long x) {
		if(t < d) {
			// Jumping can be fast than walking, so let's do that
			// a few times.
			long ret = t * (x / d); // Integer division, x/d whole jumps
			ret += Math.min(t, x % d); // for the last bit, walk or jump
			return ret;
		}
		return x;
	}
}

