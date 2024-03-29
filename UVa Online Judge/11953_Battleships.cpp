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
char g[105][105];
int n;
void dfs(int i, int j) {
  if (i >= n || j >= n || i < 0 || j < 0) return;
  if (g[i][j] == '.') return;
  g[i][j] = '.';
  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i, j + 1);
  dfs(i, j - 1);
}
int main() {
  int cases = 0, i, j;
  scanf("%*d");
  while (scanf("%d", &n) == 1) {
    for (i = 0; i < n; i++) scanf("%s", g[i]);
    int res = 0;
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if (g[i][j] == 'x') res++, dfs(i, j);
    printf("Case %d: %d\n", ++cases, res);
  }
  return 0;
}