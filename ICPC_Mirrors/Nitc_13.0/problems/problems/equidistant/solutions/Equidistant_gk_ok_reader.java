import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class Equidistant_gk_ok_reader {
    private static Scanner in;
    private static PrintStream out;

    private static class Solution {
        private List<List<Integer>> edges;
        private int[] depths;
        private int[] ups;

        void run() {
            final int n = in.nextInt();
            final int m = in.nextInt();
            edges = Stream.<List<Integer>>generate(ArrayList::new).limit(n)
                    .collect(Collectors.toList());

            for (int i = 0; i < n - 1; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                edges.get(u).add(v);
                edges.get(v).add(u);
            }
            final int[] teams = IntStream.generate(in::nextInt).limit(m).map(i -> i - 1).toArray();

            depths = new int[n];
            ups = new int[n];
            dfs(teams[0], teams[0], 0);
            final int deepest = IntStream.of(teams).boxed().max(Comparator.comparing(i -> depths[i])).get();
            final int depth = depths[deepest];
            if (depth % 2 != 0) {
                out.println("NO");
                return;
            }
            int middle = deepest;

            for (int i = 0; i < depth / 2; i++) {
                middle = ups[middle];
            }
            dfs(middle, middle, 0);

            if (IntStream.of(teams).allMatch(team -> depths[team] == depth / 2)) {
                out.println("YES");
                out.println(middle + 1);
            } else {
                out.println("NO");
            }
        }

        private void dfs(final int team, final int up, final int depth) {
            depths[team] = depth;
            ups[team] = up;
            for (final int v : edges.get(team)) {
                if (v != up) {
                    dfs(v, team, depth + 1);
                }
            }
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        out = System.out;

        new Solution().run();
    }

    static class Scanner implements AutoCloseable {
        final BufferedReader reader;
        StringTokenizer tokenizer = new StringTokenizer("");

        Scanner(InputStream is) {
            reader = new BufferedReader(new InputStreamReader(is));
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        String next() {
            while (!tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new AssertionError();
                }
            }
            return tokenizer.nextToken();
        }

        public void close() {
        }
    }
}
