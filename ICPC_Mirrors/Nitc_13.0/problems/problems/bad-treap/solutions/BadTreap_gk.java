import java.io.PrintStream;
import java.util.*;
import java.util.stream.Stream;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class BadTreap_gk {
    private static Scanner in;
    private static PrintStream out;

    private static class Solution {
        static final int MAX_N = 50_000;
        static final int STEP = 710;

        void run() {
//            int bestStep = 0;
//            double bestMod = 2 * Math.PI;
//            for (int i = 1; i < Integer.MAX_VALUE / MAX_N; i++) {
//                double mod = i % (2 * Math.PI);
//                if (bestMod > mod) {
//                    bestMod = mod;
//                    bestStep = i;
//                }
//            }
//            System.out.println(bestStep + " " + bestMod * MAX_N / 2);
//            System.out.println((2 * Math.PI - bestMod) * MAX_N +  " " + Math.sin(bestStep * MAX_N));

            final int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                out.println((i - MAX_N / 2) * STEP);
            }
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        out = System.out;

        new Solution().run();
    }
}
