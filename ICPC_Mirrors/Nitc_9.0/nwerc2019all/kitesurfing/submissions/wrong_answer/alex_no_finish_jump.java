import java.util.ArrayList;
import java.util.Scanner;

class alex_no_finish_jump {

  // returns the minimal time to move on water
  private static long move(long distance, long d, long t) {
    if(t > d) return distance;
    long time = (distance / d) * t;
    distance %= d;
    if(t > distance) return time + distance;
    return time + t;
  }

  // returns -1 if it isn't possible to instantly jump between another set of islands from position
  // otherwise returns the furthest body of water reachable with a jump from position
  private static int jump_next_index(ArrayList<Long> jumptable, long position) {
    if(jumptable.get(0) > position) return -1;
    int low = 0, high = jumptable.size();
    while(low + 1 < high) {
      int mid = (low + high) / 2;
      if(jumptable.get(mid) > position) high = mid;
      else low = mid;
    }
    return low;
  }


  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long s = sc.nextLong();
    long d = sc.nextLong();
    long t = sc.nextLong();
    int n = sc.nextInt() + 1;
    long[][] water = new long[n][2];
    water[0][0] = 0;
    ArrayList<ArrayList<Long>> jumptables = new ArrayList<ArrayList<Long>>();
    for(int i = 0; i < n - 1; i++) {
      water[i][1] = sc.nextLong();
      water[i + 1][0] = sc.nextLong();
    }
    water[n - 1][1] = s;
    long jump_to_finish = s - d;
    for(int i = 0; i < n; i++) {
      final ArrayList<Long> cur_jumptable = new ArrayList<Long>();
      for(int j = i + 1; j < n; j++) {
        long start = Math.max(water[i][0], water[j][0] - d);
        if(start > water[i][1]) break;
        cur_jumptable.add(start);
      }
      jumptables.add(cur_jumptable);
    }
    long dp[] = new long[n];
    dp[n-1] = move(s - water[n-1][0], d, t);
    for(int i = n - 2; i >= 0; i--) {
      long best = Long.MAX_VALUE;
      long cur_pos = water[i][0];
      int cur_w = i;
      long cur_t = 0;
      while(cur_w < n - 1) {
        if(jump_to_finish <= cur_pos) {
          cur_t += t;
          cur_pos = s;
          cur_w = n - 1;
          break;
        }
        final ArrayList<Long> cur_jumptable = jumptables.get(cur_w);
        int inst_jump = jump_next_index(cur_jumptable, cur_pos);
        for(int j = inst_jump + 1; j < cur_jumptable.size(); j++) {
          best = Math.min(best, cur_t + move(cur_jumptable.get(j) - cur_pos, d, t) + t + dp[cur_w + j + 1]);
        }
        if(inst_jump == -1) {
          cur_t = best;
          cur_pos = s;
          cur_w = n-1;
        } else {
          cur_w = cur_w + inst_jump + 1;
          cur_pos = Math.min(Math.min(cur_pos + d, water[cur_w][1]), s);
          cur_t += t;
        }
      }
      cur_t += move(s - cur_pos, d, t);
      dp[i] = Math.min(best, cur_t);
    }
    System.out.println(dp[0]);
  }
}
