import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Equidistant_bm_tl {
    FastScanner in;
    PrintWriter out;

    List<Integer>[] g;
    final int MAX = 20;
    int[][] up;
    int[] h;

    void go(int v, int p) {
        h[v] = h[p] + 1;
        up[0][v] = p;
        for (int i = 1; i < MAX; i++) {
            up[i][v] = up[i - 1][up[i - 1][v]];
        }
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            go(to, v);
        }
    }

    int up(int x, int dH) {
        for (int i = 0; i < MAX; i++) {
            if (((1 << i) & dH) != 0) {
                x = up[i][x];
            }
        }
        return x;
    }

    int lca(int x, int y) {
        if (h[x] > h[y]) {
            x = up(x, h[x] - h[y]);
        } else {
            y = up(y, h[y] - h[x]);
        }
        for (int i = MAX - 1; i >= 0; i--) {
            if (up[i][x] != up[i][y]) {
                x = up[i][x];
                y = up[i][y];
            }
        }
        return x == y ? x : up[0][x];
    }

    int dist(int x, int y) {
        return h[x] + h[y] - 2 * h[lca(x, y)];
    }

    int getVertexBetween(int x, int y) {
        if (h[x] > h[y]) {
            return getVertexBetween(y, x);
        }
        return up(y, dist(x, y) / 2);
    }

    boolean check(int v, int[] teams) {
        int dist = dist(v, teams[0]);
        for (int t : teams) {
            if (dist(v, t) != dist) {
                return false;
            }
        }
        return true;
    }

    int findAnswer(int[] teams) {
        int maxHV = teams[0];
        for (int t : teams) {
            if (h[t] > h[maxHV]) {
                maxHV = t;
            }
        }
        while (true) {
            if (check(maxHV, teams)) {
                return maxHV;
            }
            if (up[0][maxHV] == maxHV) {
                return -1;
            }
            maxHV = up[0][maxHV];
        }
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        h = new int[n];
        up = new int[MAX][n];
        go(0, 0);
        int[] teams = new int[m];
        for (int i = 0; i < m; i++) {
            teams[i] = in.nextInt() - 1;
        }
        int res = findAnswer(teams);
        if (res == -1) {
            out.println("NO");
        } else {
            out.println("YES");
            out.println(res + 1);
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Equidistant_bm_tl().runIO();
    }
}
