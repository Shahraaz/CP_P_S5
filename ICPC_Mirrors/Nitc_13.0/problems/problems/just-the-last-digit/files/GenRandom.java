import java.io.PrintWriter;
import java.util.*;

public class GenRandom {

    public final static int SEED = "graph-count".hashCode();
    public final static Random rng = new Random(SEED);
    public final static int ARGS_COUNT = 2;
    public final static int MAX_N = 500;

    public static void main(String[] args) {
        if (args.length < ARGS_COUNT) {
            throw new IllegalArgumentException(
                    String.format("Expected %d arguments, but got %d instead", ARGS_COUNT, args.length));
        }
        rng.setSeed(Arrays.hashCode(args));
        int n = Integer.parseInt(args[0]);
        double density = Double.parseDouble(args[1]);

        printTest(generateRandom(n, density));
    }

    static TestCase generateRandom(int n, double density) {
        int[][] graph = new int[n][n];
        int[][] count = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                graph[i][j] = (rng.nextDouble() < density) ? 1 : 0;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (graph[i][j] == 1) {
                    count[i][j] = (count[i][j] + 1) % 10;
                    for (int k = j + 1; k < n; k++) {
                        count[i][k] = (count[i][k] + count[j][k]) % 10;
                    }
                }
            }
        }
        return new TestCase(count);
    }

    static void printTest(TestCase test) {
        try (PrintWriter out = new PrintWriter(System.out)) {
            int n = test.count.length;
            out.println(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    out.print(test.count[i][j]);
                }
                out.println();
            }
        }
    }

    static class TestCase {
        int[][] count;

        public TestCase(int[][] count) {
            this.count = count;
        }
    }
}
