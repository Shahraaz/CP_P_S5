import java.util.*;

public class Paul {
	final long INF = Long.MAX_VALUE/2;
	
	class Edge {
		int a, b, length;

		Edge(int a, int b, int length) {
			this.a = a;
			this.b = b;
			this.length = length;
		}
	}
	
	class Line {
		long slope, intercept;
		
		Line(long slope, long intercept) {
			this.slope = slope;
			this.intercept = intercept;
		}

		double intersect(Line l) {
			assert(slope != l.slope);
			return (double)(intercept - l.intercept) / (l.slope - slope);
		}
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();

		Edge[] edges = new Edge[m];
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			int length = sc.nextInt();
			edges[i] = new Edge(a, b, length);
		}
		
		long[][] dist = new long[n][n];
		for (long[] row: dist) Arrays.fill(row, INF);
		dist[0][0] = 0;
		for (int k = 0; k+1 < n; k++) {
			for (Edge e: edges) {
				dist[k+1][e.b] = Math.min(dist[k+1][e.b], dist[k][e.a] + e.length);
				dist[k+1][e.a] = Math.min(dist[k+1][e.a], dist[k][e.b] + e.length);
			}
		}
		
		Line[] lines = new Line[n];
		for (int k = 0; k < n; k++) {
			if (dist[k][n-1] == INF) continue;
			lines[k] = new Line(k, dist[k][n-1]);
		}
		
		boolean[][] onOptimalPath = new boolean[n][n];

		for (int i = 0; i < n; i++) {
			if (lines[i] == null) continue;
			
			double hi = 1e18;
			for (int j = 0; j < i; j++) {
				if (lines[j] == null) continue;
				hi = Math.min(hi, lines[i].intersect(lines[j]));
			}
			
			double lo = 0;
			for (int j = i+1; j < n; j++) {
				if (lines[j] == null) continue;
				lo = Math.max(lo, lines[i].intersect(lines[j]));
			}
			
			onOptimalPath[i][n-1] = lo <= hi;
		}
		
		for (int k = n-2; k >= 0; k--) {
			for (Edge e: edges) {
				if (dist[k+1][e.b] == dist[k][e.a] + e.length && onOptimalPath[k+1][e.b]) {
					onOptimalPath[k][e.a] = true;
				}
				if (dist[k+1][e.a] == dist[k][e.b] + e.length && onOptimalPath[k+1][e.a]) {
					onOptimalPath[k][e.b] = true;
				}
			}
		}
		
		List<Integer> res = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			boolean isRedundant = true;
			for (int k = 0; k < n; k++) {
				if (onOptimalPath[k][i]) {
					isRedundant = false;
				}
			}
			if (isRedundant) {
				res.add(i);
			}
		}
		
		System.out.println(res.size());
		for (int x: res) System.out.print((x+1) + " ");
		System.out.println();
	}

	public static void main(String[] args) {
		new Paul().run();
	}
}
