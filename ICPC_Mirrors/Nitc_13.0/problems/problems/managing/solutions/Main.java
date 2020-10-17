import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCount = scanner.nextInt();
        for (int test = 0; test < testCount; test++) {
            int n = scanner.nextInt();
            List<Integer> a = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                a.add(scanner.nextInt());
            }
            int ans = 0;
            Map<Integer, Integer> cnts = new HashMap<Integer, Integer>();
            for (int j = n - 1; j >= 0; j--) {
                for (int i = 0; i < j; i++) {
                    int ak = a.get(j) + a.get(j) - a.get(i);
                    if (cnts.containsKey(ak)) {
                        ans += cnts.get(ak);
                    }
                }
                if (cnts.containsKey(a.get(j))) {
                    cnts.put(a.get(j), cnts.get(a.get(j)) + 1);
                } else {
                    cnts.put(a.get(j), 1);
                }
            }
            System.out.println(ans);
        }
    }
}
