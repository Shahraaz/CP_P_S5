import ru.ifmo.validate.ValidatingScanner;
import ru.ifmo.validate.Validator;
import ru.ifmo.validate.ValidatorFramework;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public class Validate implements Validator {

    private char[][] pattern;
    private int w;
    private int h;

    @Override
    public void validate(ValidatingScanner in) {
        w = in.nextInt("w", 1, 100);
        h = in.nextInt("h", 1, 100);
        in.eoln();

        pattern = new char[h][];
        for (int r = 0; r < h; r++) {
        	String line = in.nextLine(w, w);
            if (!line.matches("[.X]+")) {
                throw new AssertionError();
            }
        	pattern[r] = line.toCharArray();
        }

        int components = 0;
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (pattern[r][c] == 'X') {
                    components++;
                    fill(r, c);
                }
            }
        }
        if (components != 1) {
            throw new AssertionError("Number of components: " + components);
        }
    }

    private void fill(final int r, final int c) {
        if (r < 0 || h <= r || c < 0 || w <= c || pattern[r][c] != 'X') {
            return;
        }

        pattern[r][c] = '!';

        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                fill(r + dr, c + dc);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        ClassLoader.getSystemClassLoader().setDefaultAssertionStatus(true);
        ValidatorFramework.main(args);
    }
}
