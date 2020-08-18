import java.io.*;

public class Paul {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] row = br.readLine().split(" ");
		int numPlayers = Integer.valueOf(row[0]);
		int numWeeks = Integer.valueOf(row[1]);
		
		int[] score = new int[numPlayers];
		long[] res = new long[numPlayers];
		
		int[] lastModified = new int[numWeeks+1];
		int[] above = new int[numWeeks+1];
		long[] sum = new long[numWeeks+1];
		
		for (int time = 0; time < numWeeks; time++) {
			row = br.readLine().split(" ");
			for (int k = 1; k < row.length; k++) {
				int i = Integer.valueOf(row[k]) - 1;
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
