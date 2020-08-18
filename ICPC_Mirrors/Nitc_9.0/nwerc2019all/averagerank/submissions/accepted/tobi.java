import java.util.*;
import java.io.*;

public class tobi {
	public static int n, weeks, k, c;
	public static int points[] = new int[1000005];
	public static int lastUpdate[] = new int[1000005];
	public static long sumRanks[] = new long[1000005];
	public static long groupSum[] = new long[1000005];
	public static long rnk[] = new long[1000005];
	public static long joinSum[] = new long[1000005];
	public static void UPDATE(int group, int week) {
		groupSum[group] += rnk[group] * (week - lastUpdate[group]);
		lastUpdate[group] = week;
	}

	public static void leaveGroup(int week, int candidate) {
		int group = points[candidate];
		UPDATE(group, week);
		rnk[group]++;
		sumRanks[candidate] += groupSum[group] - joinSum[candidate];
	}

	public static void joinGroup(int week, int candidate) {
		int group = ++points[candidate];
		UPDATE(group, week);
		joinSum[candidate] = groupSum[group];
	}

	public static void main(String ... args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		weeks = sc.nextInt();
		for (int week = 0; week < weeks; week++) {
			k = sc.nextInt();
			for (int j = 0; j < k; j++) {
				c = sc.nextInt();
				leaveGroup(week, c);
				joinGroup(week, c);
			}
		}
		for (int i = 1; i <= n; i++) leaveGroup(weeks, i);
		for (int i = 1; i <= n; i++) System.out.println(1+(double)sumRanks[i]/weeks);
	}
}
