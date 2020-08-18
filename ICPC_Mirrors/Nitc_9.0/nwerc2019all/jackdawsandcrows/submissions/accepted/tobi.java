// This is a translation of the C++ version with the one exception that the dp array is flattened.
// The version in the dontcare directory is unflattened (and thus slow - oh Java...).
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
	public static int size4 = 2;
	public static int size3 = 2 * size4;
	public static int size2 = size3 * 5*100001;
	public static long dp[] = new long[20*size2];
	public static long items[] = new long[20];

	public static SortedSet<pair> votes = new TreeSet<>();

	public static void update(int curLayer, int idx) {
		for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) dp[curLayer*size2 + idx*size3 + j*size4 + k] = MUCH;
		for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) for (int l = 0; l < 2; l++)
			dp[curLayer*size2 + idx*size3 + j*size4 + k] = Math.min(dp[curLayer*size2 + idx*size3 + j*size4 + k], dp[(curLayer-1)*size2 + 2*idx*size3 + j*size4 + l] + dp[(curLayer-1)*size2 + (2*idx+1)*size3 + (1-l)*size4 + k]);
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
			dp[i*size3] = score < 0 ? 0 : MUCH;
			dp[i*size3 + size4 + 1] = score > 0 ? 0 : MUCH;
			dp[i*size3 + 1] = dp[i*size3 + size4] = 1;
		}
		for (layer = 1; items[layer-1] > 1; layer++) {
			items[layer] = (items[layer-1]+1) / 2;
			for(int i = 0; i < items[layer]; i++) update(layer, i);
		}
		for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) best = Math.min(best, y*dp[size2*(layer-1)+size4*i+j]);
		for (pair vote : votes) {
			int idx = vote.second;
			for (int j = 0; j < 2 ; j++) dp[size3*idx+size4*j+j] = 0;
			for (int j = 1; j < layer; j++) {
				idx /= 2;
				update(j, idx);
			}
			for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) best = Math.min(best, y*dp[size2*(layer-1)+size4*j+k] + x*vote.first);
		}
		System.out.println(best);
	}
}
