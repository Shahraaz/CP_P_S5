import java.io.*;
import java.util.*;

class pair implements Comparable {
	public long first;
	public int second;
	pair(long first, int second) {
		this.first = first;
		this.second = second;
	}

	public int compareTo(Object o) {
		if (o == null) return -1;
		if (!(o instanceof pair)) return -1;
		if (this == o) return 0;
		pair other = (pair) o;
		if (first != other.first) return first < other.first ? -1 : 1;
		return second - other.second;
	}
}

public class tobi {
	public static final long MUCH = 1000001;

	public static long score, x, y, best;
	public static int layer;
	public static long dp[][][][] = new long[20][5*100001][2][2];
	public static long items[] = new long[20];

	public static SortedSet<pair> votes = new TreeSet<>();

	public static void update(int curLayer, int idx) {
		for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) dp[curLayer][idx][j][k] = MUCH;
		for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) for (int l = 0; l < 2; l++)
			dp[curLayer][idx][j][k] = Math.min(dp[curLayer][idx][j][k], dp[curLayer-1][idx*2][j][l] + dp[curLayer-1][idx*2+1][1-l][k]);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		items[0] = sc.nextLong();
		x = sc.nextLong();
		y = sc.nextLong();
		best = y*items[0];
		for (int i = 0; i < items[0]; i++) {
			score = sc.nextLong();
			votes.add(new pair(1+Math.abs(score), i));
			dp[0][i][0][0] = score < 0 ? 0 : MUCH;
			dp[0][i][1][1] = score > 0 ? 0 : MUCH;
			dp[0][i][0][1] = dp[0][i][1][0] = 1;
		}
		for (layer = 1; items[layer-1] > 1; layer++) {
			items[layer] = (items[layer-1]+1) / 2;
			for(int i = 0; i < items[layer]; i++) update(layer, i);
		}
		for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) best = Math.min(best, y*dp[layer-1][0][i][j]);
		for (pair vote : votes) {
			int idx = vote.second;
			for (int j = 0; j < 2 ; j++) dp[0][idx][j][j] = 0;
			for (int j = 1; j < layer; j++) {
				idx /= 2;
				update(j, idx);
			}
			for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) best = Math.min(best, y*dp[layer-1][0][j][k] + x*vote.first);
		}
		System.out.println(best);
	}
}
