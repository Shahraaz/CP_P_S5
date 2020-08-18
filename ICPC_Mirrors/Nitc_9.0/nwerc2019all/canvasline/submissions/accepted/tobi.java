import java.util.*;
import java.io.*;

public class tobi {
	public static int n, p, x, candidate;
	public static int l[] = new int[1005];
	public static int r[] = new int[1005];
	public static int c[] = new int[1005];
	public static TreeSet<Integer> pegs = new TreeSet<>();

	public static void main(String ... args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			l[i] = sc.nextInt();
			r[i] = sc.nextInt();
		}
		p = sc.nextInt();
		for (int i = 0; i < p; i++) {
			x = sc.nextInt();
			pegs.add(x);
			for (int j = 0; j < n; j++) if (l[j] <= x && x <= r[j]) c[j]++;
		}
		TreeSet<Integer> origPegs = new TreeSet<>(pegs);
		for (int i = 0; i < n; i++) {
			switch (c[i]) {
				case 0:
					if (i + 1 < n && r[i] == l[i+1]) {
						if (c[i+1] <= 1) {
							pegs.add(r[i]);
						       	c[i+1]++;
						} else pegs.add(r[i]-3);
						pegs.add(r[i]-1);
					} else {
						pegs.add(r[i]-4);
						pegs.add(r[i]-1);
					}
					break;
				case 1:
					candidate = r[i];
					if (i + 1 < n && r[i] == l[i+1] && c[i+1] >= 2) candidate = r[i] - 1;
					while (pegs.contains(candidate)) candidate--;
					pegs.add(candidate);
					if (i + 1 < n && r[i] == l[i+1] && candidate == r[i]) c[i+1]++;
					break;
				case 2: break;
				default:
					System.err.println("canvas " + i + " has " + c[i] + " pegs :-/");
					System.out.println("impossible");
					return;
			}
		}
		System.out.println(pegs.size() - origPegs.size());
		for (int peg : pegs) if (!origPegs.contains(peg)) System.out.print(peg + " ");
		System.out.println("");
	}
}
