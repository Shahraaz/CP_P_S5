import java.io.IOException;
import java.io.PrintWriter;
import java.io.UncheckedIOException;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class cross_Tests {
    private static final int MAX_S = 100;

    private int tests = 1;
    private final Random random = new Random(8475083274598432750L);

    public void test(char[][] data) {
        final int[] code9 = code(data, 3, 3);
        final int[] code5v = code(data, 5, 1);
        final int[] code5h = code(data, 1, 5);
        final int[] code7v = code(data, 7, 1);
        final int[] code7h = code(data, 1, 7);

        System.out.format(
                "%02d %3d/%d %2d/%d %2d/%d %3d/%d %3d/%d%n", tests,
                distinct(code9), code9.length,
                distinct(code5v), code5v.length,
                distinct(code5h), code5h.length,
                distinct(code7v), code7v.length,
                distinct(code7h), code7h.length
        );

        try {
            try (PrintWriter out = new PrintWriter(String.format("%02d", tests++))) {
                out.println(data[0].length + " " + data.length);
                for (final char[] row : data) {
                    out.println(row);
                }
            }
        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
    }

    private long distinct(final int[] code9) {
        return Arrays.stream(code9).filter(i -> i > 0).count();
    }

    private int[] code(final char[][] data, final int mr, final int mc) {
        final int[] code9 = new int[1 << (mr * mc)];
        for (int r = 0; r < data.length - mr; r++) {
            for (int c = 0; c < data[0].length - mc; c++) {
                int code = 0;
                for (int dr = 0; dr < mr; dr++) {
                    for (int dc = 0; dc < mc; dc++) {
                        code = (code << 1) + (data[r + dr][c + dc] == 'X' ? 1 : 0);
                    }
                }
                code9[code]++;
            }
        }
        return code9;
    }

    public void run() {
        test(new char[][]{{'X', 'X'}, {'.', 'X'}});

        for (int r = 1; r <= 3; r++) {
            for (int c = 1; c <= 3; c++) {
                full(r, c);
            }
        }

        for (int s : new int[]{30, MAX_S}) {
            full(10, almost(s));
            full(almost(s), 10);
            full(s, s);

            random(almost(s), 12, s * 12 / 5, 100, 0);
            random(5, almost(s), s, 0, 0);
            random(s, s, s * s / 3, 100, 0.5);
            final int bound = s * s / 10;
            test(addRandom(randomInt(bound), checkers(s, s, 1, 1)));
            test(addRandom(randomInt(s * s / 10), checkers(s, s, randomInt(s / 2) + 1, 1)));
            test(addRandom(randomInt(s * s / 20), checkers45(s, s, 1, 1)));
            test(addRandom(randomInt(s * s / 10), checkers(s, s, 1, randomInt(s / 2) + 1)));
            test(addRandom(randomInt(s * s / 10), checkers(s, s, randomInt(s / 2) + 1, randomInt(s / 2) + 1)));
            test(addRandom(randomInt(s * s / 20), checkers45(s, s, randomInt(s / 10) * 2 + 5, randomInt(s / 10) * 2 + 5)));
        }

        test(lattice9());
        test(lattice7());
        test(transpose(lattice7()));
    }

    private char[][] transpose(final char[][] pattern) {
        final char[][] result = new char[pattern[0].length][pattern.length];
        for (int i = 0; i < pattern.length; i++) {
            for (int j = 0; j < pattern[i].length; j++) {
                result[j][i] = pattern[i][j];
            }
        }
        return result;
    }

    private char[][] lattice7() {
        final int R = MAX_S / 3;
        final int C = (int) Math.ceil((1 << 7) / R);
        final char[][] pattern = lattice(R * 2 + 1, C * 8 + 1, 2, 8);

        final List<Integer> codes = IntStream.range(0, R * C).boxed().collect(Collectors.toList());
//        Collections.shuffle(codes, random);

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int code = (codes.get(r * C + c)) & ((1 << 7) - 1);
                for (int dc = 0; dc < 7; dc++) {
                    pattern[r * 2 + 1][c * 8 + dc + 1] = x((code & 1) == 1);
                    code >>= 1;
                }
            }
        }
        return pattern;
    }

    private int almost(final int s) {
        return s * 9 / 10 + randomInt(s / 10);
    }

    private char[][] lattice(final int r, final int c, final int dr, final int dc) {
        final char[][] pattern = new char[r][c];
        for (int i =  0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                pattern[i][j] = x(i % dr == 0 || j % dc == 0);
            }
        }
        return pattern;
    }

    private char[][] lattice9() {
        final int s = (int) Math.ceil(Math.sqrt(1 << 9));
        final char[][] pattern = lattice(s * 4 + 1, s * 4 + 1, 4, 4);

        final List<Integer> codes = IntStream.range(0, s * s).boxed().collect(Collectors.toList());
        Collections.shuffle(codes, random);

        for (int r = 0; r < s; r++) {
            for (int c = 0; c < s; c++) {
                int code = (codes.get(r * s + c)) & ((1 << 9) - 1);
                if (code  == 1 << 4) {
                    code = 0;
                }
                for (int dr = 0; dr < 3; dr++) {
                    for (int dc = 0; dc < 3; dc++) {
                        pattern[r * 4 + dr + 1][c * 4 + dc + 1] = x((code & 1) == 1);
                        code >>= 1;
                    }
                }
            }
        }
        return pattern;
    }

    private char x(final boolean b) {
        return b ? 'X' : '.';
    }

    private int randomInt(final int bound) {
        return random.nextInt(bound);
    }

    private char[][] addRandom(final int n, final char[][] pattern) {
        for (int i = 0; i < n; i++) {
            int r, c;
            do {
                r = randomInt(pattern.length);
                c = randomInt(pattern[r].length);
            } while (!connected(pattern, r, c));
            pattern[r][c] = 'X';
        }
        return pattern;
    }

    private boolean connected(final char[][] pattern, final int r, final int c) {
        if (pattern[r][c] == 'X') {
            return false;
        }
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (0 <= r + dr && r + dr < pattern.length && 0 <= c + dc && c + dc < pattern[r + dr].length && pattern[r + dr][c + dc] == 'X') {
                    return true;
                }
            }
        }
        return false;
    }

    class Cross {
        private final int r, c, dr, dc, weight;

        Cross(final int r, final int c, final int dr, final int dc, final int weight) {
            this.r = r;
            this.c = c;
            this.dr = dr;
            this.dc = dc;
            this.weight = weight;
        }

        @Override
        public String toString() {
            return r + " " + c + " " + weight;
        }
    }

    private char[][] checkers(int r, int c, int dr, int dc) {
        int sr = randomInt(2 * dr);
        int sc = randomInt(2 * dc);
        char[][] pattern = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                pattern[i][j] = x(((i + sr) % (2 * dr) < dr) ^ ((j + sc) % (2 * dc) < dc));
            }
        }
        return pattern;
    }

    private char[][] checkers45(int r, int c, int dr, int dc) {
        int sr;
        int sc;
        do {
            sr = randomInt(2 * dr);
            sc = randomInt(2 * dc);
        } while (invalid45(r, dr, sr) || invalid45(c, dc, sc) || odd(sr + sc)
        );
        System.out.println(tests + " " + (r + sr) % dr + " " + dr);
        char[][] pattern = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                pattern[i][j] = x(odd(i + j) && (((i + sr) % (2 * dr) < dr) ^ ((j + sc) % (2 * dc) < dc)));
            }
        }
        return pattern;
    }

    private boolean invalid45(final int r, final int dr, final int sr) {
        return dr > 1 && (sr % dr == 1 || sr % dr == dr - 1 || (r + sr) % dr == 1 || (r + sr) % dr == dr - 1);
    }

    private boolean odd(final int i1) {
        return i1 % 2 == 1;
    }

    private void random(final int r, final int c, final int n, final int directionWeight, final double parentWeight) {
        final char[][] pattern = filled(r, c, '.');
        final List<Cross> crosses = new ArrayList<>();
        boolean[][] used = new boolean[r][c];
        final int cr = randomInt(r);
        final int cc = randomInt(c);
        add(crosses, used, cr, cc, 0, 0, 1);

        for (int i = 0; i < n; i++) {
            final int rand = random.nextInt(crosses.stream().mapToInt(cross -> cross.weight).sum());
            int sum = 0;
            for (Cross cross : crosses) {
                sum += cross.weight;
                if (rand < sum) {
                    if (pattern[cross.r][cross.c] == 'X') {
                        throw new AssertionError("double cross " + cross.r + " " + cross.c + " " + used[cross.r][cross.c]);
                    }
                    pattern[cross.r][cross.c] = 'X';
                    for (int dr = -1; dr <= 1; dr++) {
                        for (int dc = -1; dc <= 1; dc++) {
                            add(crosses, used, cross.r + dr, cross.c + dc, dr, dc, 1 + (2 + cross.dr * dr + cross.dc * dc) * directionWeight + (int) Math.round(cross.weight * parentWeight));
                        }
                    }
                    crosses.remove(cross);
                    break;
                }
            }
        }
        test(pattern);
    }

    private void add(final List<Cross> crosses, final boolean[][] used, final int r, final int c, final int dr, final int dc, final int weight) {
        if (r < 0 || used.length <= r || c < 0 || used[r].length <= c || used[r][c]) {
            return;
        }

        used[r][c] = true;
        crosses.add(new Cross(r, c, dr, dc, weight));
    }

    private void full(final int r, final int c) {
        test(filled(r, c, 'X'));
    }

    private char[][] filled(final int r, final int c, final char ch) {
        final String row = new String(new char[c]).replace('\0', ch);
        return Stream.generate(row::toCharArray).limit(r).toArray(char[][]::new);
    }

    public static void main(String[] args) {
        new cross_Tests().run();
    }
}