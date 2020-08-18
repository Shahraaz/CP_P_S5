import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class jeroen {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {
		// Read input
		int n = Integer.valueOf(in.readLine());
		int[] v = new int[n];
		String[] ps = in.readLine().split(" ");
		for(int i = 0; i < n; i++)
			v[i] = Integer.valueOf(ps[i]);

		// It works if we have a non-decreasing, then
		// non-increasing, and then non-decreasing sequence
		int i = 0;
		while(i < n - 2 && v[i] <= v[i+1]) i++;
		while(i > 0     && v[i-1] == v[i]) i--;
		int j = i;
		while(j < n - 1 && v[j] >= v[j+1]) j++;
		int k = j + 1;
		while(k < n - 1 && v[k] <= v[k+1]) k++;

		if(k < n - 1 || (i > 0 && v[j] < v[i-1]) || (j < n - 1 && v[i] > v[j+1]))
			System.out.println("impossible");
		else
			System.out.println((i+1) + " " + (j+1));
	}
}
