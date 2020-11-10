// Author: Luka Kalinovcic

#include <algorithm>
#include <cstdio>

using namespace std;

int max(int a, int b, int c, int d) { return max(max(a, b), max(c, d)); }

const int MAXN = 200000;
const int MAXM = 3000;
const int M = MAXM + 10;
short a[M][M];
short b[M][M];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    char type;
    int x, y, len;
    scanf(" %c%d%d%d", &type, &x, &y, &len);
    if (type == 'A')
    {
      const int x0 = M / 2 + x - len / 2;
      const int y0 = M / 2 + y - len / 2;
      a[x0][y0] = max((int)a[x0][y0], len);
    }
    else
    {
      const int x0 = M / 2 + x - len / 2;
      const int y0 = M / 2 + y;
      b[x0][y0] = max((int)b[x0][y0], len);
    }
  }

  double ret = 0.0;
  for (int x = 1; x < M - 1; ++x)
  {
    for (int y = 1; y < M - 1; ++y)
    {
      a[x][y] = max(a[x][y],
                    a[x - 1][y] - 1, a[x - 1][y - 1] - 1, a[x][y - 1] - 1);
      b[x][y] = max(b[x][y],
                    b[x - 1][y] - 1, b[x - 1][y - 1] - 2, b[x - 1][y + 1] - 2);
      if (a[x][y - 1] >= 1)
      {
        ret += 1.0;
      }
      else
      {
        if (b[x][y - 1] >= 1)
          ret += 0.25;
        if (b[x][y] >= 1)
          ret += 0.25;
        if (b[x][y - 1] >= 2 || b[x][y] >= 2)
          ret += 0.25;
        if (b[x - 1][y - 1] >= 2 || b[x - 1][y] >= 2)
          ret += 0.25;
      }
    }
  }
  printf("%.2lf\n", ret);
  return 0;
}
