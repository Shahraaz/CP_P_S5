import java.io.*;
import java.util.*;

public class Rgl {
  public static void main(String[] args) throws IOException {
    final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    final int n = Integer.parseInt(br.readLine());
    final long[] v = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();

    int i = 0, j = v.length-1;
    while (i+1< j && v[i] <= v[i+1]) ++i;
    while (i >= 1 && v[i] <= v[i-1]) --i;
    while (j  > i && v[j] >= v[j-1]) --j;
    while (j+1< n && v[j] >= v[j+1]) ++j;

    for (int k=0; i+k < j-k; k++) {
      long tmp = v[i+k];
      v[i+k] = v[j-k];
      v[j-k] = tmp;
    }

    for (int k = 1; k < n; k++) {
      if (v[k] < v[k-1]) {
        System.out.println("iMpOsSiBlE");
        return;
      }
    }

    System.out.printf("%d %d\n", i+1, j+1);
  }
}
