import java.util.HashSet;
import java.util.Scanner;

class alex {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long[][] canvas = new long[n][3];
    HashSet<Long> pegs = new HashSet<Long>();
    HashSet<Long> new_pegs = new HashSet<Long>();
    for(int i = 0; i < n; i++) {
      canvas[i][0] = sc.nextLong();
      canvas[i][1] = sc.nextLong();
    }
    int p = sc.nextInt();
    int index = 0;
    while(p-- > 0) {
      long x = sc.nextLong();
      pegs.add(x);
      while(index < n && canvas[index][1] < x) index++;
      if(index >= n) break;
      if(canvas[index][0] <= x) canvas[index][2]++;
      if(index < n - 1 && canvas[index + 1][0] <= x) canvas[index + 1][2]++;
    }
    // try edges
    for(int i = 0; i < n - 1; i++) {
      if(canvas[i][2] < 2 && !pegs.contains(canvas[i][1])) {
        if(canvas[i + 1][0] > canvas[i][1] || canvas[i + 1][2] < 2) {
          pegs.add(canvas[i][1]);
          new_pegs.add(canvas[i][1]);
          canvas[i][2]++;
          if(canvas[i + 1][0] == canvas[i][1]) canvas[i + 1][2]++;
        }
      }
    }
    for(int i = 0; i < n; i++) {
      if(canvas[i][2] < 2 && (i == 0 || canvas[i - 1][1] < canvas[i][0]) && !pegs.contains(canvas[i][0])) {
        pegs.add(canvas[i][0]);
        new_pegs.add(canvas[i][0]);
        canvas[i][2]++;
      }
      for(long j = canvas[i][0] + 1; j < canvas[i][1] && canvas[i][2] < 2; j++) {
        if(!pegs.contains(j)) {
          pegs.add(j);
          new_pegs.add(j);
          canvas[i][2]++;
        }
      }
    }
    if(canvas[n - 1][2] < 2 && !pegs.contains(canvas[n - 1][1])) {
      canvas[n - 1][2]++;
      pegs.add(canvas[n - 1][1]);
      new_pegs.add(canvas[n - 1][1]);
    }
    boolean ok = true;
    for(int i = 0; i < n; i++) {
      ok &= canvas[i][2] == 2;
    }
    if(ok) {
      System.out.println(new_pegs.size());
      for(Long peg : new_pegs) System.out.print(peg + " ");
      System.out.println();
    } else {
      System.out.println("impossible");
      }
  }
}
