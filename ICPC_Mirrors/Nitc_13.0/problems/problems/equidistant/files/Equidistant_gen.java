import java.io.*;
import java.util.*;

public class Equidistant_gen {
    PrintWriter out;

    static Random rnd;

    void addEdge(List<Integer>[] g, int fr, int to) {
        g[fr].add(to);
        g[to].add(fr);
    }

    int[] genPerm(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            int j = rnd.nextInt(i + 1);
            res[i] = res[j];
            res[j] = i;
        }
        return res;
    }

    void setRandomMtoTrue(boolean[] a, int m) {
        for (int i = 0; i < m; i++) {
            int x = rnd.nextInt(a.length);
            if (a[x]) {
                i--;
                continue;
            }
            a[x] = true;
        }
    }

    void solve() {
        int n = 1 + rnd.nextInt(maxN);
        if (useMax) {
            n = maxN;
        }
        int m = 1 + rnd.nextInt(Math.min(maxM == 0 ? n : maxM, n));
        if (useMax) {
            m = Math.min(n, maxM);
        }
        List<Integer>[] g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        boolean[] teamInCity = new boolean[n];
        if (testType.equals("random")) {
            Dsu dsu = new Dsu(n);
            for (int i = 0; i + 1 < n; i++) {
                int fr = rnd.nextInt(n);
                int to = rnd.nextInt(n);
                if (dsu.get(fr) == dsu.get(to)) {
                    i--;
                    continue;
                }
                g[fr].add(to);
                g[to].add(fr);
                dsu.unite(fr, to);
            }
            m = useRandomRootAndLayer(n, m, g, teamInCity);
        } else if (testType.equals("random2")) {
            int up = 1 + rnd.nextInt(Math.min(n, 100));
            for (int i = 1; i < n; i++) {
                int parent = Math.max(0, i - 1 - rnd.nextInt(up));
                addEdge(g, parent, i);
            }
            m = useRandomRootAndLayer(n, m, g, teamInCity);
        } else if (testType.equals("spec1")) {
            /*
             *                           *
             *                          /
             *    * ----------X--------/-*
             *                         \
             *                          \
             *                           *
             */
            int lenInCenter = n - m;
            if (lenInCenter % 2 == 0 && ansShouldExist) {
                n--;
                lenInCenter--;
            }
            for (int i = 0; i < lenInCenter; i++) {
                addEdge(g, i, i + 1);
            }
            for (int i = lenInCenter + 1; i < n; i++) {
                addEdge(g, lenInCenter, i);
                teamInCity[i] = true;
            }
            teamInCity[0] = true;
        } else if (testType.equals("one_line")) {
            for (int i = 1; i < n; i++) {
                addEdge(g, i, i - 1);
            }
            setRandomMtoTrue(teamInCity, m);
        } else if (testType.equals("full_binary")) {
            int[] height = new int[n];
            for (int i = 1; i < n; i++) {
                height[i] = height[(i - 1) / 2] + 1;
                addEdge(g, i, (i - 1) / 2);
            }
            m = setTeamsByHeight(n, m, teamInCity, height);
        } else if (testType.equals("sun")) {
            int[] height = new int[n];
            for (int i = 1; i < n; i++) {
                height[i] = height[Math.max(0, i - m)] + 1;
                addEdge(g, i, Math.max(0, i - m));
            }
            m = setTeamsByHeight(n, m, teamInCity, height);
        } else {
            throw new AssertionError();
        }
        out.println(n + " " + m);
        int[] perm = genPerm(n);
        for (int i = 0; i < n; i++) {
            for (int to : g[i]) {
                if (to > i) {
                    out.println((perm[i] + 1) + " " + (perm[to] + 1));
                }
            }
        }
        int[] teamsAfterPerm = new int[m];
        for (int i = 0; i < n; i++) {
            if (teamInCity[i]) {
                teamsAfterPerm[--m] = perm[i];
            }
        }
        Arrays.sort(teamsAfterPerm);
        for (int i = 0; i < teamsAfterPerm.length; i++) {
            out.print(teamsAfterPerm[i] + 1);
            if (i != teamsAfterPerm.length - 1) {
                out.print(" ");
            }

        }
        out.println();
    }

    private int useRandomRootAndLayer(int n, int m, List<Integer>[] g, boolean[] teamInCity) {
        if (ansShouldExist) {
            List<Integer>[] onLevel = new List[n + 1];
            for (int i = 0; i < onLevel.length; i++) {
                onLevel[i] = new ArrayList<>();
            }
            getOnLevel(rnd.nextInt(n), -1, 0, onLevel, g);
            int firstNotOkLevel = 0;
            while (!onLevel[firstNotOkLevel].isEmpty()) {
                firstNotOkLevel++;
            }
            int useLevel = rnd.nextInt(firstNotOkLevel);
            List<Integer> vertexOnLevel = onLevel[useLevel];
            m = Math.min(m, vertexOnLevel.size());
            for (int i = 0; i < m; i++) {
                int v = vertexOnLevel.get(rnd.nextInt(vertexOnLevel.size()));
                if (!teamInCity[v]) {
                    teamInCity[v] = true;
                } else {
                    i--;
                }
            }
        } else {
            setRandomMtoTrue(teamInCity, m);
        }
        return m;
    }

    private int setTeamsByHeight(int n, int m, boolean[] teamInCity, int[] height) {
        if (ansShouldExist) {
            int useHeight = height[height.length - 1];
            if (rnd.nextBoolean()) {
                useHeight--;
            }
            m = 0;
            for (int i = 0; i < n; i++) {
                if (height[i] == useHeight) {
                    teamInCity[i] = true;
                    m++;
                }
            }
        } else {
            setRandomMtoTrue(teamInCity, m);
        }
        return m;
    }

    void getOnLevel(int v, int p, int curH, List<Integer>[] onLevel, List<Integer>[] g) {
        onLevel[curH].add(v);
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            getOnLevel(to, v, curH + 1, onLevel, g);
        }
    }

    class Dsu {
        int[] p;

        Dsu(int n) {
            p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
        }

        int get(int x) {
            return p[x] == x ? x : (p[x] = get(p[x]));
        }

        void unite(int x, int y) {
            p[get(x)] = get(y);
        }
    }

    void runIO() {
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    static int maxN, maxM;
    static boolean useMax, ansShouldExist;
    static String testType;

    static void parsArg(String arg) {
        String[] tmp = arg.split("=");
        String param = tmp[0], value = tmp[1];
        if (param.equals("max_n")) {
            maxN = Integer.parseInt(value);
        } else if (param.equals("max_m")) {
            maxM = Integer.parseInt(value);
        } else if (param.equals("use_max")) {
            useMax = Boolean.parseBoolean(value);
        } else if (param.equals("type")) {
            testType = value;
        } else if (param.equals("ans_exist")) {
            ansShouldExist = Boolean.parseBoolean(value);
        } else {
            throw new AssertionError("Unknown field: " + param);

        }
    }

    public static void main(String[] args) {
        for (int i = 0; i + 1 < args.length; i++) {
            parsArg(args[i]);
        }
        rnd = new Random(Long.parseLong(args[args.length - 1]));
        new Equidistant_gen().runIO();
    }
}
