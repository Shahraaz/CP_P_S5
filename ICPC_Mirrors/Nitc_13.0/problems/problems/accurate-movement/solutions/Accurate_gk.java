import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class Accurate_gk {
    private static Scanner in;
    private static PrintStream out;

    private static class Solution {
        void run() {
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();

            out.println(1 + (n - b + b - a - 1) / (b - a) * 2);
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        out = System.out;

        new Solution().run();
    }
}
