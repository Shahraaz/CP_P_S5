import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class jeroen_bf {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		// Read input
		String[] ps = in.readLine().split(" ");
		int s = Integer.valueOf(ps[0]);
		int d = Integer.valueOf(ps[1]);
		int t = Integer.valueOf(ps[2]);

		int n = Integer.valueOf(in.readLine());
		int[] l = new int[n];
		int[] r = new int[n];
		for(int i = 0; i < n; i++) {
			ps = in.readLine().split(" ");
			l[i] = Integer.valueOf(ps[0]);
			r[i] = Integer.valueOf(ps[1]);
		}

		// Simple brute-force dp
		boolean[] island = new boolean[s+1];
		boolean[] islandend = new boolean[s+1];
		for(int i = 0; i < n; i++) {
			for(int j = l[i] + 1; j < r[i]; j++)
				island[j] = true;
			islandend[r[i]] = true;
		}

		int[] best = new int[s+1];
		for(int i = 1; i <= s; i++) {
			if(island[i]) continue;
			best[i] = Integer.MAX_VALUE / 3;
			for(int j = 1; j <= d; j++)
				if(i-j>=0 && !island[i-j])
					best[i] = Math.min(best[i], best[i-j] + (j == 1 && !islandend[i] ? 1 : t));
		}

		System.out.println(best[s]);
	}
}
