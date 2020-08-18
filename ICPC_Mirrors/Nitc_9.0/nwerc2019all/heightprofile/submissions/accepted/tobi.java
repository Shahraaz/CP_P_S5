import java.io.*;
import java.util.*;

class pair {
	int first;
	double second;
	pair(int first, double second) {
		this.first = first;
		this.second = second;
	}
}

public class tobi {
	static long n, k;
	static long heights[] = new long[100005];
	static double g;
	static double diffs[] = new double[100005];
	static ArrayList<pair> candidates = new ArrayList<>();

	public static void main(String... args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextLong();
		k = scanner.nextLong();
		n++;
		for (int i = 0; i < n; i++) heights[i] = scanner.nextLong();
		for (int i = 0; i < k; i++) {
			double best = 0;
			g = scanner.nextDouble();
			long wanted = (long)(g*10);
			for (int j = 0; j < n; j++) diffs[j] = heights[j] - wanted * j;
			candidates.clear();
			candidates.add(new pair(0, diffs[0]));
			for (int j = 1; j < n; j++) {
				int a = 0, o = candidates.size();
				while (a < o) {
					int m = (a + o) / 2;
					if (candidates.get(m).second <= diffs[j]) o = m;
					else a = m + 1;
				}
				if (a < candidates.size()) {
					int idx = candidates.get(a).first;
					while (idx > 0 && diffs[idx-1] <= diffs[j]) idx--;
					double streak = j - idx;
					best = Math.max(best, streak);
					if (idx > 0 && diffs[idx] != diffs[idx-1]) best = Math.max(best, streak + 1 - Math.min(1., (diffs[j] - diffs[idx-1]) / (diffs[idx] - diffs[idx-1])));
					if (j < n - 1 && diffs[j] != diffs[j+1]) best = Math.max(best, streak + Math.min(1., (diffs[j] - diffs[idx]) / (diffs[j] - diffs[j+1])));
				}
				if (diffs[j] < candidates.get(candidates.size() - 1).second) candidates.add(new pair(j, diffs[j]));
			}
			if (best == 0) System.out.println("impossible");
			else System.out.printf("%20.20f\n", best);
		}
	}
}
