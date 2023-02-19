#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 255;
int st_max[N][N][10], st_min[N][N][10];
int a[N][N];
int lb[N];

void initLog() {
  lb[0] = -1;
  for (int i = 1; i <= N; i++)
    lb[i] = (i & (i - 1)) ? lb[i - 1] : lb[i - 1] + 1;
}

void initST(int n) {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++) st_max[k][i][0] = st_min[k][i][0] = a[k][i];

  for (int k = 1; k <= n; k++)
    for (int j = 1; j <= lb[n]; j++)
      for (int i = 1; i <= n - (1 << j) + 1; i++) {
        st_max[k][i][j] =
            max(st_max[k][i][j - 1], st_max[k][i + (1 << (j - 1))][j - 1]);
        st_min[k][i][j] =
            min(st_min[k][i][j - 1], st_min[k][i + (1 << (j - 1))][j - 1]);
      }
}

void solve(int x, int y, int b) {
  int k = lb[b];
  int Max = -1;
  int Min = 0x3f3f3f3f;
  int l = y;
  int r = y + b - 1;
  for (int i = x; i < x + b; i++) {
    Max = max(Max, max(st_max[i][l][k], st_max[i][r - (1 << k) + 1][k]));
    Min = min(Min, min(st_min[i][l][k], st_min[i][r - (1 << k) + 1][k]));
  }

  cout << Max - Min << endl;
}

int main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif
  int n, b, k;
  initLog();
  while (~scanf("%d%d%d\n", &n, &b, &k)) {
    memset(st_max, 0, sizeof(st_max));
    memset(st_min, 0, sizeof(st_min));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    }
    initST(n);
    for (int i = 1; i <= k; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      solve(x, y, b);
    }
  }

  return 0;
}