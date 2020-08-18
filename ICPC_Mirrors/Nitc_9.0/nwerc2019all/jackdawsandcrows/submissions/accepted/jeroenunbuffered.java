import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class jeroenunbuffered {
	//static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static Scanner in = new Scanner(System.in);

	static int n;
	static long[] a;

	public static void main(String[] args) throws Exception {
		// Read input
		n = in.nextInt();
		long x = in.nextInt();
		long y = in.nextInt();
		a = new long[n];

		for(int i = 0; i < n; i++) a[i] = in.nextInt();

		// Build the tree
		leaves = new Leaf[n];
		TreeNode root = buildTree(0, n - 1);

		// The initial answer when we don't up-/downvote
		long ans = Long.MAX_VALUE;
		for(int i = 0; i < 4; i++) {
			boolean firstPos = (i & 1) > 0;
			boolean lastPos  = (i & 2) > 0;
			ans = Math.min(ans, root.minRemovals(firstPos, lastPos) * y);
		}
		
		// Now sort the nodes by absolute value, so we
		// increase the number of votes needed from
		// small to large
		Item[] items = new Item[n];
		for(int i = 0; i < n; i++)
			items[i] = new Item(Math.abs(a[i]), i);
		Arrays.sort(items);

		// Find the best answer by increasing the
		// number of votes and updating the
		// result in O(log n) time.
		for(int i = 0; i < n; i++) {
			// Remove an item by invalidating it and the
			// chain above it
			for(TreeNode inv = leaves[items[i].idx]; inv != null; inv = inv.parent)
				inv.Invalidate();	

			// Update answer
			for(int j = 0; j < 4; j++) {
				boolean firstPos = (j & 1) > 0;
				boolean lastPos  = (j & 2) > 0;
				ans = Math.min(ans, root.minRemovals(firstPos, lastPos) * y + (items[i].val + 1) * x);
			}		 
		}
		System.out.println(ans);
	}

	static Leaf[] leaves;
	
	public static TreeNode buildTree(int i, int j) {
		if(i == j) {
			leaves[i] = new Leaf(a[i]);
			return leaves[i];
		} else {
			int mid = (i + j) / 2;
			TreeNode l = buildTree(i, mid);
			TreeNode r = buildTree(mid+1, j);
			TreeNode p = new BinaryNode(l, r);
			l.parent = p;
			r.parent = p;
			return p;
		}
	}
}

abstract class TreeNode {
	public TreeNode parent;

	public abstract void Invalidate();

	public abstract long minRemovals(boolean firstPos, boolean lastPos);
}

class BinaryNode extends TreeNode {
	private TreeNode l, r;

	public BinaryNode(TreeNode l, TreeNode r) {
		this.l = l;
		this.r = r;
		this.Invalidate();
	}

	private long[][] cache;
	public void Invalidate() {
		cache = new long[2][2];
		for(int i = 0; i < 4; i++) {
			boolean firstPos = (i & 1) > 0;
			boolean lastPos  = (i & 2) > 0;
			cache[firstPos ? 1 : 0][lastPos ? 1 : 0] = 999999;
			for(int j = 0; j < 2; j++) {
				boolean midPos = j > 0;
				cache[firstPos ? 1 : 0][lastPos ? 1 : 0]
					= Math.min( cache[firstPos ? 1 : 0][lastPos ? 1 : 0],
								l.minRemovals(firstPos, midPos) + r.minRemovals(!midPos, lastPos));
			}
		}
	}
	
	public long minRemovals(boolean firstPos, boolean lastPos) {
		return cache[firstPos ? 1 : 0][lastPos ? 1 : 0];
	}
}

class Leaf extends TreeNode {
	private boolean isPos, isNeg;
	private boolean invalidated;

	public Leaf(long val) {
		this.isPos = val > 0;
		this.isNeg = val < 0;
	}
	
	public long minRemovals(boolean firstPos, boolean lastPos) {
		if(firstPos == lastPos)
			return (firstPos && isPos) || (!firstPos && isNeg) || this.invalidated ? 0 : 999999;

		return 1;
	}

	public void Invalidate() {
		this.invalidated = true;
	}
}

class Item implements Comparable<Item> {
	public long val;
	public int idx;

	public Item(long val, int idx) {
		this.val = val;
		this.idx = idx;
	}

	public int compareTo(Item other) {
		if(val < other.val)
			return -1;
		if(val > other.val)
			return 1;
		return 0;
	}
}
