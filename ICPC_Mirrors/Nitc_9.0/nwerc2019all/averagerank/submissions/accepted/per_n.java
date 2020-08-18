import java.util.StringTokenizer;
import java.io.*;

public class per_n {
    public static void main(String args[]) {
        Kattio io = new Kattio(System.in);
        int n = io.getInt();
        int d = io.getInt();
        long debt[] = new long[d+1];
        long cur_rank[] = new long[d+1];
        for (int i = 0; i <= d; ++i) cur_rank[i] = 1;
        long last_change[] = new long[d+1];
        int cur_score[] = new int[n];
        long ranksum[] = new long[n];

        for (int day = 0; day < d; ++day) {
            int k = io.getInt();
            while (k-- > 0) {
                int i = io.getInt()-1;
                int s = cur_score[i];
                ranksum[i] += (day-last_change[s])*cur_rank[s] + debt[s];
                ranksum[i] -= (day-last_change[s+1])*cur_rank[s+1] + debt[s+1];
                ++cur_score[i];
                debt[s] += (day-last_change[s])*cur_rank[s];
                ++cur_rank[s];
                last_change[s] = day;
            }
        }
        for (int i = 0; i < n; ++i) {
            int s = cur_score[i];
            long rs = ranksum[i] + (d - last_change[s])*cur_rank[s] + debt[s];
            io.println(1.0*rs/d);
        }
        io.flush();
    }
}


/** Simple yet moderately fast I/O routines.
 *
 * Example usage:
 *
 * Kattio io = new Kattio(System.in, System.out);
 *
 * while (io.hasMoreTokens()) {
 *    int n = io.getInt();
 *    double d = io.getDouble();
 *    double ans = d*n;
 *
 *    io.println("Answer: " + ans);
 * }
 *
 * io.close();
 *
 *
 * Some notes:
 *
 * - When done, you should always do io.close() or io.flush() on the
 *   Kattio-instance, otherwise, you may lose output.
 *
 * - The getInt(), getDouble(), and getLong() methods will throw an
 *   exception if there is no more data in the input, so it is generally
 *   a good idea to use hasMoreTokens() to check for end-of-file.
 *
 * @author: Kattis
 */

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }



    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}
