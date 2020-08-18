import java.io.*;
import java.util.*;

public class PaulLog {
	static class Event implements Comparable<Event> {
		int time, index;
		boolean isJoin;

		public Event(int time, int index, boolean isJoin) {
			this.time = time;
			this.index = index;
			this.isJoin = isJoin;
		}

		public int compareTo(Event e) {
			return Integer.compare(time, e.time);
		}
	};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] row = br.readLine().split(" ");
		int numPlayers = Integer.valueOf(row[0]);
		int numWeeks = Integer.valueOf(row[1]);

		List<Integer> points[] = new ArrayList[numPlayers];
		for (int i = 0; i < numPlayers; i++) {
			points[i] = new ArrayList<Integer>();
		}

		for (int k = 0; k < numWeeks; k++) {
			row = br.readLine().split(" ");
			for (int j = 1; j < row.length; j++) {
				int i = Integer.valueOf(row[j]) - 1;
				points[i].add(k);
			}
		}
	
		List<Event> events[] = new ArrayList[numWeeks+1];
		for (int i = 0; i <= numWeeks; i++) {
			events[i] = new ArrayList<Event>();
		}
		
		for (int i = 0; i < numPlayers; i++) {
			int total = 0;
			for (int time: points[i]) {
				events[total].add(new Event(time, i, false));
				total++;
				events[total].add(new Event(time, i, true));
			}
			events[total].add(new Event(numWeeks, i, false));
		}
		
		double[] res = new double[numPlayers];
		for (int total = 0; total <= numWeeks; total++) {
			Collections.sort(events[total]);
			int above = 0, time = -1;
			long sum = 0;
			for (Event e: events[total]) {
				sum += (long) (e.time-time) * above;
				time = e.time;
				if (e.isJoin) {
					res[e.index] -= sum;
				} else {
					res[e.index] += sum;
					above++;
				}
			}
		}

		for (int i = 0; i < numPlayers; i++) {
			System.out.println((double) (numWeeks+res[i])/numWeeks);
		}
	}	
}
