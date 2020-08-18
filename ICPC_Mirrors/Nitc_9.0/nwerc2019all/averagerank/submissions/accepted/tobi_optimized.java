import java.util.*;
import java.io.*;

public class tobi_optimized {
	public static int n, weeks, k, c;
	public static int points[] = new int[1000005];
	public static int lastUpdate[] = new int[1000005];
	public static long sumRanks[] = new long[1000005];
	public static long groupSum[] = new long[1000005];
	public static long rnk[] = new long[1000005];
	public static long joinSum[] = new long[1000005];

	public static void main(String ... args) throws Exception {
		BufferedReader bufRead = new BufferedReader(new InputStreamReader(System.in));
		String[] strings = bufRead.readLine().split(" ");
		n = Integer.valueOf(strings[0]);
		weeks = Integer.valueOf(strings[1]);
		for (int week = 0; week < weeks; week++) {
			strings = bufRead.readLine().split(" ");
			k = Integer.valueOf(strings[0]);
			for (int j = 0; j < k; j++) {
				c = Integer.valueOf(strings[1+j]);
				int group = points[c];
				groupSum[group] += rnk[group] * (week - lastUpdate[group]);
				lastUpdate[group] = week;
				rnk[group]++;
				sumRanks[c] += groupSum[group] - joinSum[c];
				group = ++points[c];
				groupSum[group] += rnk[group] * (week - lastUpdate[group]);
				lastUpdate[group] = week;
				joinSum[c] = groupSum[group];
			}
		}
		for (int i = 1; i <= n; i++) {
			int group = points[i];
			groupSum[group] += rnk[group] * (weeks - lastUpdate[group]);
			lastUpdate[group] = weeks;
			rnk[group]++;
			sumRanks[i] += groupSum[group] - joinSum[i];
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= n; i++) {
			sb.append(new Double(1+(double)sumRanks[i]/weeks).toString());
			sb.append('\n');
		}
		System.out.println(sb.toString());
	}
}
