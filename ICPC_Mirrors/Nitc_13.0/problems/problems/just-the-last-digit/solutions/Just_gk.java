import java.io.PrintStream;
import java.util.Scanner;
import java.util.Arrays;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class Just_gk {
    private static Scanner in;
    private static PrintStream out;

    private static class Solution {
        void run() {
            int n = in.nextInt();
            int[][] c = new int[n][n];
            for (int i = 0; i < n - 1; i++) {
                c[i] = in.next().chars().map(j -> j - '0').toArray();
                c[i] = Arrays.copyOfRange(c[i], i + 1, n);
            }

            int[][] a = new int[n][n];
            for (int d = 1; d < n; d++) {
                for (int i = 0; i + d < n; i++) {
                    int total = 0;
                    for (int k = 1; k < d; k++) {
                        total += c[i][k - 1] * a[i + k][d - k - 1];
                    }
                    total %= 10;
                    if (c[i][d - 1] != total) {
                        a[i][d - 1] = 1;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= i; j++) {
                    out.print(0);
                }
                for (int d = 0; i + d < n - 1; d++) {
                    out.print(a[i][d]);
                }
                out.println();
            }
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        out = System.out;

        new Solution().run();
    }
}
