import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class double_av {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DoubleP solver = new DoubleP();
        solver.solve(1, in, out);
        out.close();
    }

    static class DoubleP {
        int mod = 998244353;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int[] r = new int[n + 1], d = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                if (i % 2 == 0) {
                    r[i] += (long) (i / 2) * MathUtils.modPow(k, i / 2, mod) % mod;
                    r[i] += (long) (i / 2) * MathUtils.modPow(k, i / 2 + 1, mod) % mod;
                    r[i] %= mod;
                } else {
                    r[i] = (int) ((long) i * MathUtils.modPow(k, (i + 1) / 2, mod) % mod);
                }
            }
            for (int i = 1; i <= n; i++) {
                d[i] = r[i];
                for (long l : MathUtils.divisors(i)) {
                    if (l < i) {
                        d[i] += mod - (long) i / l * d[(int) l] % mod;
                        d[i] %= mod;
                    }
                }
            }
            int[] realAns = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = i; j <= n; j += i) {
                    realAns[j] += d[i];
                    realAns[j] %= mod;
                }
            }
            long sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += realAns[i];
            }
            out.println(sum % mod);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }

    static class MathUtils {
        public static int modPow(int a, long b, int mod) {
            while (a < 0) {
                a += mod;
            }
            int res = 1;
            while (b > 0) {
                if ((b & 1) != 0) {
                    res = (int) ((long) res * a % mod);
                }
                a = (int) ((long) a * a % mod);
                b >>>= 1;
            }
            return res;
        }

        public static List<Long> divisors(long x) {
            List<Long> result = new ArrayList<>();
            result.add(1L);
            if (x != 1) {
                result.add(x);
            }
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    result.add((long) i);
                    if (i * i != x) {
                        result.add(x / i);
                    }
                }
            }
            return result;
        }

    }
}

