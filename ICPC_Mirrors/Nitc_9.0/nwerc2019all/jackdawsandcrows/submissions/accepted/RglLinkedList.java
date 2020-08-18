import java.io.*;
import java.util.*;
import java.util.stream.*;

public class RglLinkedList {
  final long x, y;

  RglLinkedList(final long x, final long y) {this.x = x; this.y = y;}

  long solve(final long[] v) {
    final SimpleLinkedList l = new SimpleLinkedList(v.length);

    long cost = 0;
    for (int i = 0; i < v.length; i++) {
      cost += contributes(i, v, l) ? 1 : 0;
    }

    long res = 0;
    for (int i = 0, last = -1; i < v.length; i++) {
      if (v[i] == 0 || last != -1 && v[i] * v[last] >= 0) res += y;
      else last = i;
    }
    if (Arrays.stream(v).min().orElse(0) > 0) {
      res = Math.min(res, cost*y);
    }

    for (int i : IntStream.range(0, v.length)
        .boxed().sorted((a, b) -> Long.compare(Math.abs(v[a]), Math.abs(v[b]))).mapToInt(x -> x).toArray()) {
      if (l.exists(i)) {
        final int[] dirty = {l.l[l.l[i]], l.l[i], i, l.r[i], l.r[l.r[i]]};

        for (int j : dirty) if (l.exists(j)) cost -= contributes(j, v, l) ? 1 : 0;
        if (l.exists(l.l[i]) && v[l.l[i]] == 0) {l.delete(l.l[i]); l.delete(i);}
        else if (l.exists(l.r[i]) && v[l.r[i]] == 0) {l.delete(l.r[i]); l.delete(i);}
        final long dist = Math.abs(v[i])+1; v[i] = 0;
        for (int j : dirty) if (l.exists(j)) cost += contributes(j, v, l) ? 1 : 0;

        res = Math.min(res, dist*x+cost*y);
      }
    }
    return res;
  }

  static boolean contributes(int i, final long[] v, final SimpleLinkedList l) {
    long t = v[i];
    if (t == 0) {
      if (!l.exists(l.l[i]) || !l.exists(l.r[i])) return false;
      t = -v[l.l[i]];
    }
    return l.exists(l.r[i]) && (v[l.r[i]] != 0) && (t * v[l.r[i]] >= 0);
  }

  public static void main(String[] args) throws IOException {
    final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    final long[] nxy = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
    final long[] v = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
    System.out.println(new RglLinkedList(nxy[1], nxy[2]).solve(v));
  }

  static class SimpleLinkedList {
    final int[] l, r;
    SimpleLinkedList(int n) {
     l = new int[n+1];
     r = new int[n+1];
     for (int i = 0; i < n; i++) {
       l[i] = i - 1;
       r[i] = i + 1;
     }
     l[0] = n; l[n] = n; r[n] = n;
    }

    boolean exists(int x) {return l[x] != x;}

    void delete(int x) {
      if (l[x] != r.length-1) r[l[x]] = r[x];
      if (r[x] != l.length-1) l[r[x]] = l[x];
      l[x] = x; r[x] = x;
    }
  };


}
