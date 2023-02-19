#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 30;
char g[N][N], buf[N];
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
int r, c;
int dfs(int R, int C) {
  if (R < 0 || C < 0 || g[R][C] != '1') return 0;
  int sum = 1;
  g[R][C] = '0';
  for (int i = 0; i < 8; i++) sum += dfs(R + dx[i], C + dy[i]);
  return sum;
}

int main(void) {
  int t;
  scanf("%d", &t);
  gets(buf);
  gets(buf);
  while (t--) {
    r = 0;
    while (gets(g[r]))
      if (!g[r++][0]) break;

    int ans = 0;
    for (int i = 0; i < r; i++)
      for (int j = 0; g[i][j]; j++)
        if (g[i][j] == '1') ans = max(dfs(i, j), ans);

    printf("%d\n", ans);
    if (t) puts("");
  }

  return 0;
}
