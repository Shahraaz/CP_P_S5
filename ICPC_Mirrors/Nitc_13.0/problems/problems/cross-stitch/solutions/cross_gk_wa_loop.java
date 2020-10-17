import java.io.PrintStream;
import java.util.*;
import java.util.stream.Stream;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class cross_gk_wa_loop {
    private static Scanner in;

    private static PrintStream out;

    private static class Hole {
        private final int r, c;

        public Hole(final int r, final int c) {
            this.r = r;
            this.c = c;
        }

        @Override
        public boolean equals(final Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            final Hole hole = (Hole) o;
            return r == hole.r &&
                    c == hole.c;
        }

        @Override
        public int hashCode() {
            return Objects.hash(r, c);
        }

        @Override
        public String toString() {
            return String.format("(%d, %d)", r, c);
        }
    }

    private static class Solution {
        private Map<Hole, List<Hole>> face = new HashMap<>();
        private Map<Hole, List<Hole>> back = new HashMap<>();
        private List<Hole> answer = new ArrayList<>();

        void run() {
            final int w = in.nextInt();
            final int h = in.nextInt();
            in.nextLine();
            final char[][] pattern = Stream.generate(in::nextLine).limit(h)
                    .map(String::toCharArray)
                    .toArray(char[][]::new);

            Hole start = null;
            for (int r = 0; r < h; r++) {
                for (int c = 0; c < w; c++) {
                    if (pattern[r][c] == 'X') {
                        stitch(face, r, c, r + 1, c + 1);
                        stitch(face, r, c + 1, r + 1, c);
                        stitch(back, r, c, r + 1, c);
                        stitch(back, r, c + 1, r + 1, c + 1);
                        start = new Hole(r, c);
                    }
                }
            }

            find(start, true);

            out.println(answer.size() - 1);
            for (final Hole hole : answer) {
                out.println(hole.c + " " + hole.r);
            }
        }

        private void find(final Hole hole, final boolean face) {
            final Map<Hole, List<Hole>> side = face ? this.face : back;
            final List<Hole> stitches = side.get(hole);
            if (!stitches.isEmpty()) {
                final Hole next = stitches.remove(stitches.size() - 1);
                side.get(next).remove(hole);
                find(next, !face);
                answer.add(hole);
            }
        }

        private void stitch(final Map<Hole, List<Hole>> side, final int r1, final int c1, final int r2, final int c2) {
            final Hole from = new Hole(r1, c1);
            final Hole to = new Hole(r2, c2);
            side.computeIfAbsent(from, k -> new ArrayList<>()).add(to);
            side.computeIfAbsent(to, k -> new ArrayList<>()).add(from);
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        out = System.out;

        new Solution().run();
    }
}
