import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.CheckerFramework;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;

import java.util.HashSet;
import java.util.Objects;
import java.util.Set;
import java.util.stream.Stream;

import static ru.ifmo.testlib.Outcome.Type.*;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class Check implements Checker {
    private static final int MAX_S = 100;

    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        int w = inf.nextInt();
        int h = inf.nextInt();
        inf.nextLine();

        char[][] pattern = Stream.generate(inf::nextLine).limit(h)
                .map(String::toCharArray)
                .toArray(char[][]::new);
        final Set<Stitch> stitches = new HashSet<>();
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (pattern[r][c] == 'X') {
                    stitches.add(stitch(r, c, r + 1, c + 1));
                    stitches.add(stitch(r + 1, c, r, c + 1));
                }
            }
        }

        long jury = check(ans, FAIL, stitches);
        long user = check(ouf, WA, stitches);
        if (user != jury) {
            return new Outcome(user > jury ? WA : FAIL, String.format("Expected sqrt(%d), found sqrt(%d)", jury, user));
        } else {
            return new Outcome(OK, String.format("sqrt(%d)", jury));
        }
    }

    private static class Stitch {
        private final int r1, c1, r2, c2;

        Stitch(final int r1, final int c1, final int r2, final int c2) {
            this.r1 = r1;
            this.c1 = c1;
            this.r2 = r2;
            this.c2 = c2;
        }

        @Override
        public boolean equals(final Object o) {
            Stitch that = (Stitch) o;
            return this.r1 == that.r1 && this.c1 == that.c1 && this.r2 == that.r2 && this.c2 == that.c2
                    || this.r1 == that.r2 && this.c1 == that.c2 && this.r2 == that.r1 && this.c2 == that.c1;
        }

        @Override
        public int hashCode() {
            return Objects.hash(r1, c1, r2, c2) + Objects.hash(r2, c2, r1, c1);
        }

        @Override
        public String toString() {
            return String.format("(%d, %d)-(%d, %d)", c1, r1, c2, r2);
        }

        public int length() {
            return (r1 - r2) * (r1 - r2) + (c1 - c2) * (c1 - c2);
        }
    }

    private static Stitch stitch(final int r1, final int c1, final int r2, final int c2) {
        return r1 < r2 || r1 == r2 && c1 < c2 ? new Stitch(r1, c1, r2, c2) : new Stitch(r2, c2, r1, c1);
    }

    private long check(final InStream f, final Outcome.Type o, final Set<Stitch> stitches) {
        int n = f.nextInt();
        if (n < 0) {
            throw new Outcome(o, String.format("Negative number of stitches: %d", n));
        } else if (n > MAX_S * MAX_S * 10) {
            throw new Outcome(o, String.format("Too many stitches: %d", n));
        }
        
        int[] x = new int[n + 1];
        int[] y = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            x[i] = f.nextInt();
            y[i] = f.nextInt();
        }

        final HashSet<Stitch> used = new HashSet<>();
        long total = 0;
        for (int i = 0; i < n; i++) {
            Stitch stitch = new Stitch(y[i], x[i], y[i + 1], x[i + 1]);
            if (stitch.length() == 0) {
                throw new Outcome(
                        o,
                        String.format("Stitch %d %s has zero length", i + 1, stitch)
                );
            }
            if (i % 2 == 0) {
                if (!stitches.contains(stitch)) {
                    throw new Outcome(
                            o,
                            String.format("Invalid face stitch %d %s", i + 1, stitch)
                    );
                }
                if (!used.add(stitch)) {
                    throw new Outcome(
                            o,
                            String.format("Duplicate face stitch %d %s %s", i + 1, stitch, used)
                    );
                }
            }
            total += stitch.length();
        }

        if (stitches.size() != used.size()) {
            throw new Outcome(
                    o,
                    String.format("%d face stitches missing", stitches.size() - used.size())
            );
        }

        return total;
    }

    public static void main(String[] args) {
        CheckerFramework.main(args);
    }
}
