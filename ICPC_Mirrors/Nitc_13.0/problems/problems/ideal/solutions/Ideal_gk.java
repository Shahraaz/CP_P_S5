import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class Ideal_gk {
    private static Scanner in;
    private static PrintStream out;

    private static class Solution {
        void run() {
            int n = in.nextInt();
            long minX = Long.MAX_VALUE;
            long maxX = Long.MIN_VALUE;
            long minY = Long.MAX_VALUE;
            long maxY = Long.MIN_VALUE;
            
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                int h = in.nextInt();
                minX = Math.min(minX, x - h);
                maxX = Math.max(maxX, x + h);
                minY = Math.min(minY, y - h);
                maxY = Math.max(maxY, y + h);
            }
            out.println((maxX + minX) / 2 + " " + (maxY + minY) / 2 + " " + (Math.max(maxY - minY, maxX - minX) + 1) / 2);
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        out = System.out;

        new Solution().run();
    }
}
