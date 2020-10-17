/******************************************************************/
/* ICPC 2019-2020, NERC                                           */
/* Northwestern Russia Regional Contest                           */
/* St Petersburg, October 26, 2019                                */
/******************************************************************/
/* Problem G. Golf Time                                           */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/*                       Gennady Korotkevich                      */
/* Problem statement     Gennady Korotkevich                      */
/* Test set              Mikhail Dvorkin                          */
/*                       Georgiy Korneev                          */
/*                       Gennady Korotkevich                      */
/******************************************************************/
/* Tests                                                          */
/*                                                                */
/* Author                Mikhail Dvorkin                          */
/*                       Georgiy Korneev                          */
/*                       Gennady Korotkevich                      */
/******************************************************************/

import java.io.*;
import java.nio.file.*;
import java.util.*;

public class Tests {
    private static int nTests = 0;
    private static int MAX_C;
    private static int MAX_W;
    private static final int MAX_N = 1000;
    private static final int MAX_T = 100;

    private static List<V> al = new ArrayList<>();
    private static List<V> temp = new ArrayList<>();

    private static final Random random = new Random(352845825408578547L);

    public static void main(String[] args) throws IOException {
        test(10, 8, Arrays.asList(
            v(1, 4),
            v(1, 5),
            v(3, 5),
            v(3, 6),
            v(4, 6),
            v(4, 4)
        ), Arrays.asList(
            v(2, 2),
            v(1, 7),
            v(4, 7),
            v(7, 5)
//            ,v(1, 6)
        ));

        test(6, 6, Arrays.asList(
            v(2, 2),
            v(4, 2),
            v(4, 4),
            v(2, 4)
        ), Arrays.asList(
            v(5, 5),
            v(5, 2),
            v(5, 5)
        ));

        test(4, 4, Arrays.asList(
            v(1, 1),
            v(1, 2),
            v(2, 2),
            v(2, 1)
        ), Arrays.asList(
            v(1, 3)
        ));

        for (int mode = 0; mode < 3; mode++) {
          if (mode == 0) {
            MAX_C = 1000;
            MAX_W = 1000;
          }
          if (mode == 1) {
            MAX_C = 1_000_000;
            MAX_W = 500_000_000;
          }
          if (mode == 2) {
            MAX_C = 250_000_000 - 2;
            MAX_W = 500_000_000;
          }
          test(Arrays.asList(
              v(1, 1),
              v(6, 1),
              v(6, 4),
              v(3, 4),
              v(3, 3),
              v(5, 3),
              v(5, 2),
              v(2, 2),
              v(2, 3),
              v(1, 3)
          ));
          test(v(-1, -1), v(1, -1), v(1, 1), v(-1, 1));
          test(v(MAX_C -3, MAX_C -2), v(MAX_C -3, MAX_C), v(MAX_C , MAX_C ), v(MAX_C , MAX_C -2));

          int size;

          //4 Квадрат с сильными вогнутостями по углам
          for (int d = 0; d < 4; d++) {
              fwLt(7);
              fwLt(1);
              fwRt(1);
              fwRt(3);
              fwRt(3);
              fwLt(1);
              fwLt(1);
          }
          test();

          //5 Два соединенных искаженных ромба
          size = 10;
          hill(1, 0, size, 1, 1);
          hill(0, 1, size, 1, 1);
          hill(-1, 0, size, 1, 1);
          hill(0, -1, size, 1, 1);
          test();

          //6 Небольшая система лестниц
          random.nextBoolean();
          int t = 10;
          stairs(t, 2);
          stairs2(t, 2);
          stairs(t, 2);
          snake(10 * t);
          left();
          snake(10 * t);
          left();
          stairs(t, 2);
          stairs2(t, 2);
          stairs(t, 2);
          snake(10 * t);
          left();
          snake(10 * t);
          left();
          test();

          //7 Квадрат с вырезанными прямоугольниками по углам
          y = -MAX_C;
          for (int d = 0; d < 4; d++) {
              int a = random(MAX_C / 3, 2 * MAX_C / 3);
              int b = random(MAX_C / 3, 2 * MAX_C / 3);
              fwLt(MAX_C - a);
              fwRt(b);
              fwLt(a);
              fw(MAX_C - b);
          }
          test();

          //8 Две рядом стоящие спирали
          size = 200000;
          spiral(4, size, 5000, true);
          fwLt(size + size / 100);
          spiral(4, size, 8000, true);
          fw(size - size / 100);
          test();

          //9 Винт с двумя лопастями
          for (int i = 0; i < 100; i++) {
              double angle = 2 * Math.PI * i / 100;
              double random = 1000 + 800 * Math.sin(2 * Math.PI * i / 50);
              temp(random * Math.cos(angle), random * Math.sin(angle));
          }
          make(true);
          test();

          //10 Цветок с пятью лепестками
          for (int i = 0; i < 100; i++) {
              double angle = 2 * Math.PI * (i + 17) / 100;
              double random = 2000 + 800 * Math.sin(2 * Math.PI * i / 20);
              temp(random * Math.cos(angle), random * Math.sin(angle));
          }
          make(true);
          test();

          //11 Ежик с квадратным туловищем
          for (int d = 0; d < 4; d++) {
              hairbrush(10, MAX_C / 100, MAX_C / 10, MAX_C / 300, false);
              left();
          }
          test();

          //12 Композиция из дуг и отрезков
          for (int i = 0; i < 90; i++) {
              double random = 566 + 239 * Math.cos(2 * i / 15);
              double angle = 2 * Math.PI * i / 90;
              temp(random * Math.cos(angle), random * Math.sin(angle));
          }
          make(true);
          test();

          //13 Наклонная спираль
          size = 9 * 3;
          for (int i = size; i >= 4; i -= 3) {
              stairs(i, 1);
              right();
              stairs(i, 1);
              right();
          }
          left();
          fwLt(3);
          stairs(3, 1);
          left();
          for (int i = 8; i <= size - 2; i += 3) {
              stairs(i, 1);
              left();
              stairs(i, 1);
              left();
          }
          right();
          fw(1);
          test();

          //14 Квадратная спираль
          size = MAX_C - 1;
          move(-size, -size);
          spiral(MAX_N / 4, size * 2, 1, true);
          fw(size * 2);
          test();

          //15 Тарелка с макаронами на подносе
          size = 18;
          left();
          for (int i = 0; i < size; i++) {
              stairs((int) Math.sqrt(size * size - (2 * i - size) * (2 * i - size)), 1);
              right();
              fwRt(3);
              stairs((int) Math.sqrt(size * size - (2 * i + 1 - size) * (2 * i + 1 - size)), 1);
              left();
              fwLt(1);
          }
          right(); right();
          fwRt(4);
          stairs(8, 1);
          fwRt(size * 4);
          move(x, 0);
          test();

          //16 Пушистая бахрома
          size = 6;
          fwRt(0);
          fwRt(1);
          hairbrush2(size, size * 10, 3, 1, true);
          right();
          fw(1);
          test();

          //17 Четыре наклонные кривые Пеано, выпирающие наружу
          for (int d = 0; d < 4; d++) {
              fw(MAX_C / 1000);
              peano(1 << 4, MAX_C >> 8);
              fwRt(MAX_C / 1000);
          }
          make(true);
          test();

          //18 Четыре кривые Пеано и четыре кардиограммы
          size = 23;
          for (int d = 0; d < 4; d++) {
              snake(size, 1, 10);
              peano(Integer.highestOneBit(size), 1);
              right();
          }
          test();

          //19 Четыре наклонные кривые Пеано, торчащие внутрь квадрата
          for (int d = 0; d < 4; d++) {
              for (int i = 0; i < 10; i++) fw(MAX_C / 1000);
              peano(1 << 4, MAX_C / 100 >> 4);
              for (int i = 0; i < 10; i++) fw(MAX_C / 1000);
              left();
          }
          make(true);
          test();

          //20 Заросли камышей
          size = 25;
          fwLt(0);
          fwLt(10);
          hairbrush2(size, size * 3, 12, 12, false);
          left();
          fw(10);
          test();

          //21 Наклонный прямоугольник с бахромой на сторонах
          size = 120;
          hairbrush2(10, 30, size, size, false);
          left();
          hairbrush2(30, 300, size, size, false);
          left();
          hairbrush2(10, 30, size, size, false);
          left();
          hairbrush2(30, 300, size, size, false);
          make(false);
          test();

          //22 Фрактальное множество с хаусдорфовой размерностью 1.585
          fw(0);
          fractal(64 - 4, 1, true);
          test();

          //23 Лестницы с размерами ступенек по степеням двойки
          size = 400;
          for (int d = 0; d < 2; d++) {
              for (int i = 1; i < size; i++) {
                  fwRt(zeroes(i));
                  fwLt(zeroes(i));
              }
              fwRt(1);
              for (int i = 5; i < size / 5; i++) {
                  fwRt(zeroes(i) * 96);
                  fwLt(zeroes(i) * 96);
                  if (i == 75) {
                      snake(14, size / 10, size / 2);
                  }
              }
              fwRt(1);
          }
          test();

          //24 Пятичленный цветок кипрея
          size = 500;
          for (int i = 0; i < size; i++) {
              double random = MAX_C / 3
                      + MAX_C / 10 * Math.cos(20 * Math.PI * i / size)
                      + MAX_C / 10 * Math.cos(30 * Math.PI * i / size);
              double angle = 2 * Math.PI * i / size + 0.1;
              temp(random * Math.cos(angle), random * Math.sin(angle));
          }
          make(false);
          test();

          //25 Неровная, но выпуклая окружность
          size = 500;
          for (int i = 0; i < size; i++) {
              double random = MAX_C * 0.99
                      - size / 10 * Math.cos(20 * Math.PI * i / size)
                      - size / 108 * Math.cos(30 * Math.PI * i / size);
              double angle = 2 * Math.PI * i / size + 0.1;
              temp(random * Math.cos(angle), random * Math.sin(angle));
          }
          make(false);
          test();
        }

        test(MAX_W, MAX_W, Arrays.asList(
            v(1, 1),
            v(1, 2),
            v(2, 2),
            v(2, 1)
        ));

        test(MAX_W, MAX_W - 1, Arrays.asList(
            v(1, 1),
            v(1, 2),
            v(2, 2),
            v(2, 1)
        ));

        test(MAX_W - 1, MAX_W, Arrays.asList(
            v(1, 1),
            v(1, 2),
            v(2, 2),
            v(2, 1)
        ));

        test(MAX_W, MAX_W - 10, Arrays.asList(
            v(1, 1),
            v(1, 2),
            v(2, 2),
            v(2, 1)
        ));

        System.err.println("done");
    }

    private static void fwRt(final int step) {
        fw(step);
        right();
    }

    private static void fwLt(final int step) {
        fw(step);
        left();
    }

    private static void test(final V... vs) {
        test(Arrays.asList(vs));
    }

    private static void test(final List<V> vs) {
      int minX = (int) 2e9;
      int minY = (int) 2e9;
      int maxX = -(int) 2e9;
      int maxY = -(int) 2e9;
      for (V v : vs) {
        minX = Math.min(minX, v.x);
        minY = Math.min(minY, v.y);
        maxX = Math.max(maxX, v.x);
        maxY = Math.max(maxY, v.y);
      }
      List<V> newVs = new ArrayList<V>();
      int w = maxX - minX + 3;
      if (w < MAX_W) {
        w += random.nextInt(MAX_W - w + 1);
      }
      int h = maxY - minY + 3;
      if (h < MAX_W) {
        h += random.nextInt(MAX_W - h + 1);
      }
      // maxX + dx <= w - 1
      // minX + dx >= 1
      int dx = 1 - minX + random.nextInt((w - 1 - maxX) - (1 - minX) + 1);
      int dy = 1 - minY + random.nextInt((h - 1 - maxY) - (1 - minY) + 1);
      for (V v : vs) {
        newVs.add(new V(v.x + dx, v.y + dy));
      }
      test(w, h, newVs);
    }

    private static void test(int w, int h, final List<V> newVs) {
      int n = newVs.size();
      int[] x = new int[n + 1];
      int[] y = new int[n + 1];
      int ptr = 0;
      for (V v : newVs) {
        x[ptr] = v.x;
        y[ptr] = v.y;
        ptr++;
      }
      x[n] = x[0];
      y[n] = y[0];

      List<V> qs = new ArrayList<V>();
      int t = MAX_T;
      for (int i = 0; i < t; i++) {
        while (true) {
          int xs = random.nextInt(w - 1) + 1;
          int ys = random.nextInt(h - 1) + 1;
          boolean ok = true;
          for (int j = 0; j < n; j++) {
            if (Math.min(x[j], x[j + 1]) <= xs && xs <= Math.max(x[j], x[j + 1]) &&
                Math.min(y[j], y[j + 1]) <= ys && ys <= Math.max(y[j], y[j + 1])) {
              ok = false;
              break;
            }
          }
          if (!ok) {
            continue;
          }
          int parity = 0;
          for (int j = 0; j < n; j++) {
            if (x[j] == x[j + 1] && x[j] > xs && Math.min(y[j], y[j + 1]) <= ys && ys < Math.max(y[j], y[j + 1])) {
              parity ^= 1;
            }
          }
          if (parity != 0) {
            continue;
          }
          qs.add(new V(xs, ys));
          break;
        }
      }
      test(w, h, newVs, qs);
    }

    private static void test(int w, int h, final List<V> vs, final List<V> qs) {
        try (PrintWriter out = new PrintWriter(String.format("%02d", ++nTests))) {
            System.err.println("Writing test " + nTests);
            out.println(w + " " + h);
            out.println(vs.size());
            for (V v : vs) {
                out.println(v.x + " " + v.y);
            }
            out.println(qs.size());
            for (V q : qs) {
                out.println(q.x + " " + q.y);
            }
        } catch (IOException e) {
            throw new AssertionError(e);
        }
        assert new HashSet<>(vs).size() == vs.size();
        assert vs.size() <= MAX_N : vs.size();
    }

    private static V v(int x, int y) {
        return new V(x, y);
    }

    static class V {
        int x, y;

        V(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int hashCode() {
            return (x * 31) ^ y;
        }

        @Override
        public boolean equals(Object o) {
            if (o instanceof V) {
                V v = (V) o;
                return x == v.x && y == v.y;
            }
            return false;
        }

        @Override
        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    private static int random(int low, int high) {
        return low + random.nextInt(high - low + 1);
    }

    private static void test() {
        normalize();
        int s = random(0, al.size());
        List<V> head = new ArrayList<>(al.subList(s, al.size()));
        head.addAll(al.subList(0, s));
        test(head);

        al.clear();
        temp.clear();
        x = y = 0;
        dx = 1;
        dy = 0;
    }

    private static void normalize() {
        boolean change;
        do {
            change = false;
            for (int i = al.size() - 1; i >= 0; i--) {
                if (i >= al.size())
                    continue;
                int i1 = (i + al.size() - 1) % al.size();
                int i2 = (i + 1) % al.size();
                if ((al.get(i).x == al.get(i1).x && al.get(i).x == al.get(i2).x) ||
                    (al.get(i).y == al.get(i1).y && al.get(i).y == al.get(i2).y)) {
                    change = true;
                    al.remove(i);
                }
            }
        } while (change);
    }

    private static void add(int x, int y) {
        al.add(v(x, y));
    }

    private static void move(int x, int y) {
        Tests.x = x;
        Tests.y = y;
        add(x, y);
    }

    private static int x, y;
    private static int dx = 1, dy;

    private static void snake(int dx, int dy, int steps, int step, int shift) {
        int a = 0;
        for (int i = 0; i < steps; i++) {
            x += dx * step;
            y += dy * step;
            add(x + dy * a, y + dx * a);
            if (i == steps - 1) {
                break;
            } else if (i == steps - 2) {
                a = 0;
            } else {
                a = random(-shift, shift);
            }
            add(x + dy * a, y + dx * a);
        }
    }

    private static void snake(int steps) {
        snake(dx, dy, steps, 1, 1);
    }

    private static void snake(int steps, int step, int shift) {
        snake(dx, dy, steps, step, shift);
    }

    private static void hill(int dx, int dy, int steps, int step, int shift) {
        int a = 0;
        for (int i = 0; i < steps; i++) {
            x += dx * step;
            y += dy * step;
            add(x + dy * a, y + dx * a);
            if (i == steps - 1) {
                break;
            } else if (i < steps / 2 - 1) {
                a -= shift;
            } else {
                a += shift;
            }
            add(x + dy * a, y + dx * a);
        }
    }

    private static void make(boolean random) {
        for (int i = 0; i < temp.size(); i++) {
            int i1 = (i + 1) % temp.size();
            int x1 = temp.get(i).x;
            int y1 = temp.get(i).y;
            int x2 = temp.get(i1).x;
            int y2 = temp.get(i1).y;
            if (!random || Tests.random.nextBoolean()) {
                add(x1, y2);
            } else {
                add(x2, y1);
            }
            add(x2, y2);
        }
    }

    private static void stairs(int steps, int step) {
        for (int i = 0; i < steps; i++) {
            fwLt(step);
            fwRt(step);
        }
    }

    private static void stairs2(int steps, int step) {
        fwLt(step);
        for (int i = 0; i < steps; i++) {
            fwLt(step);
            fwRt(step);
            fwRt(step);
            fwLt(3 * step);
        }
        fwRt(step);
    }

    private static void spiral(int deep, int side, int d, boolean rev) {
        side += d;
        for (int i = 0; i < deep; i++) {
            fw(side);
            turn(rev);
            fw(side);
            turn(rev);
            side -= 2 * d;
        }
        fw(d);
        turn(rev);
        for (int i = 0; i < deep - 1; i++) {
            fw(side + (i == 0 ? d : 0));
            turn(!rev);
            fw(side);
            turn(!rev);
            side += 2 * d;
        }
    }

    private static void hairbrush(int bristles, int minb, int maxb, int step, boolean rev) {
        fw(step);
        for (int i = 0; i < bristles; i++) {
            int br = random(minb, maxb);
            turn(rev);
            fw(br);
            turn(!rev);
            fw(step);
            turn(!rev);
            fw(br);
            turn(rev);
            fw(step);
        }
    }

    private static void hairbrush2(int bristles, int wid, int step, int step1, boolean rev) {
        fw(step);
        for (int i = 0; i < bristles; i++) {
            int br = random(wid / 3, wid);
            turn(rev);
            hairbrush(br / step, 34 * step / 100, 9 * step / 10, step1, rev);
            turn(!rev);
            fw(step / 2);
            turn(!rev);
            hairbrush(br / step, 34 * step / 100, 9 * step / 10, step1, rev);
            turn(rev);
            fw(2 * step);
        }
    }

    private static void peano(int n, int x, int y, int dx, int dy, int dx2, int dy2) {
        if (n == 1) {
            move(x, y);
            return;
        }
        n /= 2;
        peano(n, x, y, dx2, dy2, dx, dy);
        peano(n, x + dx2 * n, y + dy2 * n, dx, dy, dx2, dy2);
        peano(n, x + dx2 * n + dx * n, y + dy2 * n + dy * n, dx, dy, dx2, dy2);
        peano(n, x + dx * (2 * n - 1) + dx2 * (n - 1), y + dy * (2 * n - 1) + dy2 * (n - 1), -dx2, -dy2, -dx, -dy);
    }

    private static void peano(int n, int step) {
        peano(n, x, y, step * dx, step * dy, -step * dy, step * dx);
    }

    private static void fractal(int len, int step, boolean rev) {
        if (len < step) {
            fw(step);
            turn(rev);
            fw(step);
            turn(rev);
            fw(step);
            return;
        }
        int l = (len - 1) / 2;
        fw(len);
        turn(!rev);
        fractal(l, step, rev);
        turn(!rev);
        fractal(l, step, rev);
        turn(!rev);
        fractal(l, step, rev);
        turn(!rev);
        fw(len);
    }

    private static void temp(double x, double y) {
        temp.add(v((int) x, (int) y));
    }

    private static void left() {
        int dx1 = -dy;
        int dy1 = dx;
        dx = dx1;
        dy = dy1;
    }

    private static void right() {
        int dx1 = dy;
        int dy1 = -dx;
        dx = dx1;
        dy = dy1;
    }

    private static void turn(boolean where) {
        if (where) {
            left();
        } else {
            right();
        }
    }

    private static void fw(int step) {
        move(x + step * dx, y + step * dy);
    }

    private static int zeroes(int v) {
        int result = 0;
        while (v > 0 && v % 2 == 0) {
            result++;
            v /= 2;
        }
        return result;
    }
}

