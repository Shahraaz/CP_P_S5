import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class jeroen {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {
		// Read input
		int n = Integer.valueOf(in.readLine());
		TreeSet<Integer>[] persons = new TreeSet[n];
		TreeMap<Integer,ArrayList<Integer>> reverse = new TreeMap<Integer,ArrayList<Integer>>();
		for(int i = 0; i < n; i++) {
			String[] ps = in.readLine().split(" ");
			int m = Integer.valueOf(ps[0]);
			persons[i] = new TreeSet<Integer>();
			for(int j = 0; j < m; j++) {
				int p = Integer.valueOf(ps[j+1]);
				persons[i].add(p);

				if(reverse.containsKey(p)) {
					reverse.get(p).add(i);
				} else {
					ArrayList<Integer> lst = new ArrayList<Integer>();
					lst.add(i);
					reverse.put(p, lst);
				}
			}
		}

		// Run BFS to expand the graph
		HashSet<Integer> pdone = new HashSet<Integer>();
		HashSet<Integer> ndone = new HashSet<Integer>();
		Queue<Integer> q = new LinkedList<Integer>();
		ArrayList<String> ans = new ArrayList<String>();
		q.add(0);
		ndone.add(0);
		while(!q.isEmpty()) {
			int p = q.poll();
			for(int i : persons[p]) {
				if(ndone.contains(i)) continue;
				ndone.add(i);
				if(!reverse.containsKey(i)) continue;
				ArrayList<Integer> rev = reverse.get(i);
				for(int j : rev) {
					if(j == p) continue;
					if(pdone.contains(j)) continue;
					pdone.add(j);
					q.add(j);
					ans.add((p+1) + " " + (j+1) + " " + i);
				}
			}
		}

		// If the graph is connected, ans must contain n-1 lines
		if(ans.size() == n - 1) {
			for(String line : ans) {
				System.out.println(line);
			}
		} else {
			System.out.println("impossible");
		}
	}
}
