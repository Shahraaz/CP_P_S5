import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;

class alex_buffered {

  private static class Node{
    public static Node nil = new Node();
    public Node left = nil;
    public Node right = nil;
    public Node parent = nil;
    public int val = -1;
    public int original_tree_size = 0;
    public int size_needed_right = 0;
    public int current_tree_size = 0;
    boolean chosen = false;
  }

  private static ArrayList<Integer> trees = new ArrayList<Integer>();

  // Calculates the size of the subtree in original AVL-tree
  // O(n)
  private static int calculate_size(Node current) {
    if(current == Node.nil) return 0;
    int size = 1 + Math.max(calculate_size(current.left), calculate_size(current.right));
    current.original_tree_size = size;
    return size;
  }

  // Generates a subtree with garantueed depth depth_to_go
  // GENERATE algorithm
  // O(log n)
  private static void generate_depth(Node current, int depth_to_go) {
    if(depth_to_go <= 0) return;

    if(current.left.original_tree_size >= depth_to_go - 1) {
      generate_depth(current.left, depth_to_go - 1);
      if(depth_to_go > 2)
        current.size_needed_right = depth_to_go - 2;
    } else {
      generate_depth(current.left, depth_to_go - 2);
      current.size_needed_right = depth_to_go - 1;
    }
    current.chosen = true;
    current.current_tree_size = depth_to_go;
  }

  // Checks if a subtree with certain size and number of available nodes is possible
  // to create at current node
  // O(log n)
  private static boolean check_poss(Node current, Node prev, int size, int[] avail) {
    if(current == Node.nil) return true;
    int[] tmp_avail = new int[]{avail[0]};

    // we come from left
    if(prev.val < current.val) {
      if(!current.chosen) {
        if(tmp_avail[0] == 0) return false;
        tmp_avail[0]--;
      }
      int tmp_size_needed_right = current.size_needed_right;
      if(tmp_size_needed_right < size - 2) {
        tmp_avail[0] += trees.get(tmp_size_needed_right) - trees.get(size - 2);
        if(tmp_avail[0] < 0) return false;
        tmp_size_needed_right = size - 2;
      }
      if(check_poss(current.parent, current, size + 1, tmp_avail)) {
        avail[0] = tmp_avail[0];
        current.chosen = true;
        current.size_needed_right = tmp_size_needed_right;
        current.current_tree_size = Math.max(current.current_tree_size, size);
        return true;
      }
      return false;
    }

    // we come from right
    // the current node must be chosen unless it is impossible to choose this node and
    // get a valid solution
    if(!current.chosen) return false;

    // the left childtree must be at least size - 2 big to support the right childtree
    if(current.left.current_tree_size < size - 2) return false;

    if(check_poss(current.parent, current, size + 1, tmp_avail)) {
      avail[0] = tmp_avail[0];
      current.current_tree_size = Math.max(current.current_tree_size, size);
      return true;
    }

    return false;
  }

  // Try to choose a specific node with number of available nodes to spend
  // returns the number of nodes available after trying to choose the node
  // O(log n)
  private static int try_choose(Node current, int avail) {
    if(current.chosen) {
      if(current.size_needed_right > 0) 
        generate_depth(current.right, current.size_needed_right);
      return avail;
    }
    
    if(avail == 0) return 0;

    int[] tmp_avail = new int[]{avail - 1};
    if(check_poss(current.parent, current, 2, tmp_avail)) {
      current.chosen = true;
      current.current_tree_size = Math.max(current.current_tree_size, 1);
      avail = tmp_avail[0];
    }
    return avail;
  }

  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	String[] line = reader.readLine().split(" ");
    int n = Integer.parseInt(line[0]), avail = Integer.parseInt(line[1]), root = 0;
    Node[] nodes = new Node[n + 1];
    nodes[0] = Node.nil;
    for(int i = 1; i < n + 1; i++) nodes[i] = new Node();
    for(int i = 1; i < n + 1; i++) {
      nodes[i].val = i;
      int father = Integer.parseInt(reader.readLine());
      if(father == -1) {
        root = i;
        nodes[i].parent = Node.nil;
      } else {
        nodes[i].parent = nodes[father];
        if(father > i) nodes[father].left = nodes[i];
        else nodes[father].right = nodes[i];
      }
    }
    trees.add(0); trees.add(1);
    int c = 1;
    while(trees.get(c++) <= n)
      trees.add(1 + trees.get(c - 2) + trees.get(c - 1));

    calculate_size(nodes[root]);

    BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
    
    for(int i = 1; i < n + 1; i++) {
      avail = try_choose(nodes[i], avail);
      out.write(nodes[i].chosen ? '1' : '0');
    }
	out.write("\n");
	out.flush();
  }
}
