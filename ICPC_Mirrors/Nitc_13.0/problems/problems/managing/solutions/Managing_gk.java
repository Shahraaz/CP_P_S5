import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.IntStream;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class Managing_gk {
    private static Scanner in;
    private static PrintStream out;

    private static class Solution {
        void run() {
            int T = in.nextInt();
            for (int t = 0; t < T; t++) {
                int n = in.nextInt();
                int[] a = IntStream.generate(in::nextInt).limit(n).toArray();

                final Map<Integer, Integer> counts = new HashMap<>();
                int total = 0;

                for (int j = n - 1; j >= 0; j--) {
                    for (int i = 0; i < j; i++) {
                        total += counts.getOrDefault(2 * a[j] - a[i], 0);
                    }
                    counts.merge(a[j], 1, Integer::sum);
                }
                out.println(total);
            }
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        out = System.out;

        new Solution().run();
    }
}
