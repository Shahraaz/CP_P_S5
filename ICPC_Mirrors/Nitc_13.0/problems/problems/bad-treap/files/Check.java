import java.math.BigInteger;
import java.util.*;
import ru.ifmo.testlib.*;
import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
	private static BigInteger PI_NUM = new BigInteger("31415926535897932384626433832795028841971693993751");
	private static BigInteger PI_DEN = new BigInteger("10000000000000000000000000000000000000000000000000");
	private static BigInteger PI_NUM_2 = PI_NUM.shiftLeft(1);
	private static BigInteger PI_NUM_4 = PI_NUM.shiftLeft(2);

	/**
	 * Larger sin(x) <=> Larger quasiSin(x)
	 */
	private static BigInteger quasiSin(int x) {
		return BigInteger.valueOf(2L * x).multiply(PI_DEN).subtract(PI_NUM).mod(PI_NUM_4).subtract(PI_NUM_2).abs();
	}

	public Outcome test(InStream inf, InStream ouf, InStream ans) {
		int n = inf.nextInt();
		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = ouf.nextInt();
		}
		Arrays.sort(x);
		ArrayList<Integer> stack = new ArrayList<>();
		ArrayList<Integer> treeHeights = new ArrayList<>();
		int height = 0;
		for (int i = 0; i < n; i++) {
			if ((i > 0) && (x[i - 1] == x[i])) return new Outcome(WA, "Duplicate x: " + x[i]);
			int leftTree = 0;
			int x1 = x[i];
			while (!stack.isEmpty()) {
				int x0 = stack.get(stack.size() - 1);
				int diff1 = Double.compare(Math.sin(x0), Math.sin(x1));
				int diff2 = quasiSin(x0).compareTo(quasiSin(x1));
				if (diff1 * diff2 < 0) return new Outcome(FAIL, "Failed sin comparison of " + x0 + " and " + x1);
				if (diff2 == 0) return new Outcome(FAIL, "Failed quasiSin concept in " + x0 + " and " + x1);
				if (diff2 > 0) break;
				stack.remove(stack.size() - 1);
				int t = treeHeights.remove(treeHeights.size() - 1);
				leftTree = Math.max(leftTree + 1, t);
			}
			stack.add(x1);
			treeHeights.add(leftTree + 1);
			height = Math.max(height, stack.size() + leftTree);
		}
		if (height < n) return new Outcome(WA, "Height is too small: " + height + " < " + n);
		if (height > n) return new Outcome(FAIL, "Failed tree height calculation: " + height + " > " + n);
		return new Outcome(OK, "Height " + height);
	}

	public static void main(String[] args) {
		CheckerFramework.main(args);
	}
}
