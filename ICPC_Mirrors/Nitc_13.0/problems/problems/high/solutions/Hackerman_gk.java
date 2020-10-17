import java.io.*;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class Hackerman_gk {
    private static Scanner in;
    private static PrintWriter out;

    private static class Solution {
        void run() {
            int n = in.nextInt();
            int[] lens = IntStream.generate(in::nextInt).limit(n).toArray();
            int q = in.nextInt();

            int[] epochs = new int[IntStream.of(lens).sum()];
            int[] starts = new int[n];

            int ct = 0;
            for (int i = 0; i < lens.length; i++) {
                starts[i] = ct;
                for (int j = 0; j < lens[i]; j++) {
                    epochs[ct + j] = i;
                }
                ct += lens[i];
            }

            int[] times = new int[IntStream.of(lens).sum() + 1];

            for (int z = 0; z < q; z++) {
                int dt = in.nextInt();
                if (times[dt] == 0) {
                    int c = 0;
                    int t = 0;

                    while (true) {
                        c++;
                        int nt = t + dt;
                        if (nt >= epochs.length) {
                            times[dt] = c;
                            break;
                        } else if (epochs[t] == epochs[nt]) {
                            times[dt] = -1;
                            break;
                        } else {
                            t = starts[epochs[nt]];
                        }
                    }
                }
                if (times[dt] > 0) {
                    out.println(times[dt]);
                } else {
                    out.println("Impossible");
                }
            }
            out.close();
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);

        new Solution().run();
    }

    static class Scanner implements AutoCloseable {
        final BufferedReader reader;
        StringTokenizer tokenizer = new StringTokenizer("");

        Scanner(InputStream is) {
            reader = new BufferedReader(new InputStreamReader(is));
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        String next() {
            while (!tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new AssertionError();
                }
            }
            return tokenizer.nextToken();
        }

        public void close() {
        }
    }
}
