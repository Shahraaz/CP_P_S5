import java.util.Arrays;
import java.util.Scanner;

class alex_scanner {

  private static class Pair implements Comparable<Pair> {
    public long first;
    public int second;

    public Pair(long first, int second) {
      this.first = first; this.second = second;
    }

    public int compareTo(Pair other) {
      if(this.first == other.first) return Integer.compare(this.second, other.second);
      return Long.compare(this.first, other.first);
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    long h[] = new long[n + 1];
    for(int i = 0; i < n + 1; i++) h[i] = sc.nextLong();
    while(k-- > 0) {
      int inc = Math.round(10*sc.nextFloat());
      long h_adj[] = new long[n + 1];
      for(int i = 0; i < n + 1; i++) h_adj[i] = h[i] - i * inc;
      Pair h_mod[] = new Pair[n + 1];
      for(int i = 0; i < n + 1; i++) h_mod[i] = new Pair(h_adj[i], i);
      Arrays.sort(h_mod);
      int left = n + 2;
      double best = -1;
      for(Pair p : h_mod) {
        if(left > p.second){ 
          left = p.second;
        } else {
          double inbetw = 0.0;
          if(p.second + 1 < h_adj.length && h_adj[p.second] != h_adj[p.second + 1]) {
            double ext = (((double) h_adj[p.second]) - ((double)h_adj[left])) / (((double) h_adj[p.second]) - ((double) h_adj[p.second + 1]));
            inbetw = Math.max(inbetw, Math.min(1.0, ext));
          }
          if(left > 0 && h_mod[left] != h_mod[left - 1]) {
            double ext = (((double) h_adj[left]) - ((double)h_adj[p.second])) / (((double) h_adj[left]) - ((double) h_adj[left - 1]));
            inbetw = Math.max(inbetw, Math.min(1.0, ext));
          }
          best = Math.max(best, p.second - left + inbetw);
        }
      }
      if(best == -1) System.out.println("impossible");
      else System.out.println(best);
    }
  }
}
