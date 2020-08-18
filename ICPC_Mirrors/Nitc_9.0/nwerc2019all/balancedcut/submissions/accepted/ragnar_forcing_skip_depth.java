import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;
import java.io.*;
import java.math.*;

class ragnar_forcing_skip_depth {

	static int p[], l[], r[];
	static boolean take[];
	static ArrayList<ArrayList<Integer>> forced;
	static ArrayList<Integer> added = new ArrayList<Integer>();

	static int k, s, maxd = 1000000000, visits = 0;

	static boolean visit(int u){
		++visits;
		if(take[u]) return true;
		if(s==k) return false;
		for(Integer v : forced.get(u)) if(!visit(v)) return false;
		if(s==k) return false;
		take[u] = true;
		added.add(u);
		++s;
		return true;
	}

	static void dfs(int u, int d){
		if(s == k) return;
		if(d > maxd) return;
		added.clear();
		if(! visit(u)){
			s -= added.size();
			for(Integer x : added) take[x] = false;
			maxd = d-1;
			return;
		}
		if(l[u] != -1) dfs(l[u], d+1);
		if(r[u] != -1) dfs(r[u], d+1);
	}


	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String[] line = reader.readLine().split(" ");
		int n = Integer.parseInt(line[0]);
	   	k = Integer.parseInt(line[1]);

		p = new int[n];
		l = new int[n];
		r = new int[n];
		Arrays.fill(p, -1);
		Arrays.fill(l, -1);
		Arrays.fill(r, -1);
		take = new boolean[n];
		Arrays.fill(take, false);
		forced = new ArrayList<ArrayList<Integer>>(n);
		for(int i = 0; i < n; ++i) forced.add(new ArrayList<Integer>());

		int root = -1;
		for(int i = 0; i < n; ++i){
			int f = Integer.parseInt(reader.readLine());
		   	--f;
			if(f==-2){
				f = -1;
				root = i;
				continue;
			}
			p[i] = f;
			if(i > f) r[f] = i;
			else l[f] = i;
		}

		int max_depth = (int)(3+1.5*Math.log(n+2)/Math.log(2));
		// O(n * log(n)) size vector
		int first[][] = new int[n][max_depth];
		for(int i = 0; i < n; ++i) Arrays.fill(first[i], -1);

		for(int i = 0; i < n; ++i){
			first[i][0] = i;
			int d = 1;
			int u = p[i];
			while(u != -1){
				if(first[u][d] == -1)
					first[u][d] = i;
				++d;
				u = p[u];
			}
		}

		for(int i = 0; i < n; ++i){
			if(p[i] == -1) continue;
			int d = 1;
			int u = p[i];
			if(u != -1) forced.get(i).add(u);
			while(u != -1){
				if(d > 1){
					int f = first[r[u]][d-2];
					if(f != -1) forced.get(i).add(f);
				}
				u = p[u];
				++d;
			}
		}

		s = 0;

		dfs(root, 0);

		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

		for(int i = 0; i < n; ++i) {
			out.write(take[i] ? '1' : '0');
		}
		out.write("\n");
		out.flush();
	}
}
