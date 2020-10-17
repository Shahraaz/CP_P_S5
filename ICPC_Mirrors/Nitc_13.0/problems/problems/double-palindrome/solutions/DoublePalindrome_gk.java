import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class DoublePalindrome_gk {
    private static Scanner in;
    private static PrintStream out;

    private static class Solution {
        static final int MOD = 998_244_353;
        void run() {
            int n = in.nextInt();
            int k = in.nextInt();

            long[] powers = new long[n + 1];
            long[] dpolys = new long[n + 1];
            long[] total = new long[n + 1];
            powers[0] = 1;

            long all = 0;
            for (int i = 1; i <= n; i++) {
                powers[i] = mul(powers[i - 1], k);

                total[i] += i % 2 == 1
                        ? i * powers[(i + 1) / 2]
                        : mul(i / 2, powers[i / 2] + powers[i / 2 + 1]);
                dpolys[i] += total[i];

                for (int j = 2; i * j <= n; j++) {
                    total[i * j] -= mul(dpolys[i], j - 1);
                    dpolys[i * j] -= dpolys[i];
                }

                all += total[i];
            }
            out.println(all % MOD);
        }

        private long mul(final long a, final long b) {
            return (b * a) % MOD;
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
//        in = new Scanner("75 7");
        out = System.out;

        new Solution().run();
    }
}
