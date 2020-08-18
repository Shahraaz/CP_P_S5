import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class jeroen {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {
		// Read input
		String[] ps = in.readLine().split(" ");
		int n = Integer.valueOf(ps[0]);
		int k = Integer.valueOf(ps[1]);
		double[] s = new double[n];
		ps = in.readLine().split(" ");
		for(int i = 0; i < n; i++)
			s[i] = Double.valueOf(ps[i]);

		// Find each value separately
		for(int i = 0; i < n; i++) {
			// And for each result, compute how much all values can
			// add to it.
			double p = (double)k / n;
			double r = s[i] * p;
			for(int j = 1; j <= n-k; j++) {
				p *= (double)(n-k-j+1) / (n - j);
				r += s[(i-j+n)%n] * p;
			}
			if(i > 0) System.out.print(" ");
			System.out.print(r);
		}
		System.out.println();
	}
}
