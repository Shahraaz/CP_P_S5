import java.util.*;
import java.math.*;
import java.io.*;
import java.text.*;

public class Bjarki {
    static int parse(String s) {
        int res = 0;
        for (int j = 0; j < s.length(); j++) {
            char c = s.charAt(j);
            if (c == '.') continue;
            int d = c - '0';
            res = res * 10 + d;
        }
        return res;
    }

    static boolean wins(int target, int[] scores) {
        int sum = 0,
            mn = 20*100,
            mx = 0;
        for (int i = 0; i < 5; i++) {
            mn = Math.min(mn, scores[i]);
            mx = Math.max(mx, scores[i]);
            sum += scores[i];
        }

        return sum - mn - mx <= target * 3;
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, true);

        int[] scores = new int[5];
        for (int i = 0; i < 4; i++) {
            scores[i] = parse(in.next());
        }

        int target = parse(in.next());

        scores[4] = 0;
        if (!wins(target, scores)) {
            out.println("impossible");
            return;
        }

        scores[4] = 20*100;
        if (wins(target, scores)) {
            out.println("infinite");
            return;
        }

        while (!wins(target, scores)) {
            scores[4]--;
        }

        out.print(scores[4] / 100);
        out.print(".");
        out.print(scores[4] % 100 / 10);
        out.println(scores[4] % 100 % 10);
    }
}

