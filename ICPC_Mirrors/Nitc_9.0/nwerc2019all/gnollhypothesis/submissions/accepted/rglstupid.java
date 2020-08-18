import java.io.*;
import java.util.*;

public class rglstupid {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int[] nk = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    double[] v = Arrays.stream(br.readLine().split(" ")).mapToDouble(Double::parseDouble).toArray();
    int n = nk[0];
    int k = nk[0] - nk[1];

    double[] w = new double[n*2];
    for (int i = 0; i < n*2; i++)
      w[i] = v[i % n] + (i > 0 ? w[i-1] : 0);

    double[][] choose = new double[n+1][n+1];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= i; j++)
        choose[i][j] = (j == 0 || j == i ? 1 : i == 0 ? 0 : i * choose[i-1][j-1] / j);

    double[] probabilityOfRunLength = new double[n+1];
    for (int i = 1; i <= k+1; i++)
      if (n-i-1 >= 0)
        probabilityOfRunLength[i] = choose[n-i-1][k-i+1] / choose[n][k];
      else
        probabilityOfRunLength[i] = 1.0 / n;

    double[] res = new double[n];
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= n; j++)
        res[i] += (w[i+n] - w[i+n-j]) * probabilityOfRunLength[j];

    for (int i = 0; i < n; i++)
      System.out.printf("%.9f%c", res[i], i+1 == n ? '\n': ' ');
  }
}
