import java.util.*;
import java.util.stream.*;

public class Paul {
	static class UnionFind {
		int[] parent, size;

		public UnionFind(int n) {
			parent = IntStream.range(0,n).toArray();
			size = IntStream.range(0,n).map(i -> 1).toArray();
		}

		int find(int a) {
			if (a == parent[a]) return a;
			return parent[a] = find(parent[a]);
		}

		boolean union(int a, int b) {
			a = find(a);
			b = find(b);
			if (a == b) return false;
			if (size[a] > size[b]) {
				parent[b] = a;
				size[a] += size[b];
			} else {
				parent[a] = b;
				size[b] += size[a];
			}
			return true;
		}
	}

	static class Edge {
		int a, b, num;

		public Edge(int a, int b, int num) {
			this.a = a;
			this.b = b;
			this.num = num;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		Map<Integer,List<Integer>> occurrences = new HashMap<>();
		UnionFind uf = new UnionFind(n+1);
		List<Edge> result = new ArrayList<>();

		for (int a = 1; a <= n; a++) {
			int m = sc.nextInt();
			for (int j = 0; j < m; j++) {
				int x = sc.nextInt();
				if (!occurrences.containsKey(x)) {
					occurrences.put(x, new ArrayList<>());
				}
				occurrences.get(x).add(a);
			}
		}
		
		for (var entry: occurrences.entrySet()) {
			int a = entry.getValue().get(0);
			for (int b: entry.getValue()) {
				if (uf.union(a,b)) {
					result.add(new Edge(a,b,entry.getKey()));
				}
			}
		}

		if (uf.size[uf.find(1)] < n) {
			System.out.println("impossible");
		} else {
			for (Edge e: result) {
				System.out.println(e.a + " " + e.b + " " + e.num);
			}
		}
	}
}
