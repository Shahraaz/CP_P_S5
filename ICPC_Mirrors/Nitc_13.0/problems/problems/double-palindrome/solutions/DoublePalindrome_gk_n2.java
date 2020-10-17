import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class DoublePalindrome_gk_n2 {
    private static Scanner in;
    private static PrintStream out;

    private static class Solution {
        static final int MOD = 998_244_353;
        void run() {
            int n = in.nextInt();
            int k = in.nextInt();
            long[] powers = new long[n + 1];
            long[] polys = new long[n + 1];
            long[] dpolys = new long[n + 1];
            powers[0] = 1;
            polys[0] = 1;

            long all = 0;
            for (int m = 1; m <= n; m++) {
                powers[m] = mul(powers[m - 1], k);
                polys[m] = powers[(m + 1) / 2];

                long total = 0;
                for (int i = 0; i < m; i++) {
                    total += mul(polys[i], polys[m - i]);
                }
                for (int i = 1; i < m; i++) {
                    if (m % i == 0) {
                        total -= mul(dpolys[i], m / i - 1);
                    }
                }

//                total = (total % MOD + MOD) % MOD;
                dpolys[m] = total;
                for (int i = 1; i <= m / 2; i++) {
                    if (m % i == 0) {
                        dpolys[m] -= dpolys[i];
                    }
                }
//                dpolys[m] = (dpolys[m] % MOD + MOD) % MOD;
                all += total;
            }
            out.println(all % MOD);
        }

        private long mul(final long a, final long b) {
            return (b * a) % MOD;
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        out = System.out;

        new Solution().run();
    }
}
