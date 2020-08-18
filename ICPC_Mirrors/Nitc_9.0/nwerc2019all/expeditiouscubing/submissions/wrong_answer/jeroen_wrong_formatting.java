import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class jeroen_wrong_formatting {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {
		// Read input and convert to int
		String[] ps = in.readLine().split(" ");
		int[] ts = new int[4];
		for(int i = 0; i < 4; i++)
			ts[i] = toInt(ps[i]);
		int t = toInt(in.readLine());

		// Brute force
		int ans = 0;
		for(int i = 0; i <= 2001; i++) {
			int[] t2 = new int[5];
			for(int j = 0; j < 4; j++)
				t2[j] = ts[j];
			t2[4] = i;
			Arrays.sort(t2);
			if(t2[1] + t2[2] + t2[3] <= t*3) {
				ans = Math.max(ans, i);
			}
		}

		if(ans == 0)
			System.out.println("impossible");
		else if(ans > 2000)
			System.out.println("infinite");
		else
			System.out.println(toFloat(ans));
	}

	static int toInt(String x) {
		String[] ps = x.split("\\.");
		return Integer.valueOf(ps[0]) * 100 + Integer.valueOf(ps[1]);
	}

	static String toFloat(int x) {
		return String.valueOf(x/100) + "." + String.valueOf(x%100);
	}
}
