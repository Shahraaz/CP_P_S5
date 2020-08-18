import java.util.*;

public class PaulScanner {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int numPlayers = sc.nextInt();
		int numWeeks = sc.nextInt();
		
		int[] score = new int[numPlayers];
		long[] res = new long[numPlayers];
		
		int[] lastModified = new int[numWeeks+1];
		int[] above = new int[numWeeks+1];
		long[] sum = new long[numWeeks+1];
		
		for (int time = 0; time < numWeeks; time++) {
			int len = sc.nextInt();
			while (len --> 0) {
				int i = sc.nextInt() - 1;
				int j = score[i]++;
				
				sum[j] += (long) (time - lastModified[j]) * above[j];
				lastModified[j] = time;
				above[j]++;

				sum[j+1] += (long) (time - lastModified[j+1]) * above[j+1];
				lastModified[j+1] = time;
				
				res[i] += sum[j] - sum[j+1];
			}
		}
		for (int i = 0; i < numPlayers; i++) {
			int time = numWeeks;
			int j = score[i];
			sum[j] += (long) (time - lastModified[j]) * above[j];
			lastModified[j] = time;
			res[i] += sum[j];
		}
	
		for (int i = 0; i < numPlayers; i++) {
			System.out.println((double) (numWeeks+res[i])/numWeeks);
		}
	}	
}
