#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
#define INF 2147483648

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 505;
int g[N][N];
bool vis[N];
int n, m, Max = 0;
set<int> tt;
void dfs(int x) {
  for (int i = 1; i <= n; i++)
    if (g[x][i] == Max && !vis[i]) {
      vis[x] = vis[i] = 1;
      tt.insert(x);
      tt.insert(i);
      dfs(i);
    }
}
void reset() {
  for (int i = 0; i < 505; i++) {
    for (int j = 0; j < 505; j++) {
      g[i][j] = -INF;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> m) {
    if (!n && !m) break;
    reset();
    memset(vis, 0, sizeof vis);
    Max = -INF;
    for (int i = 1; i <= m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      if (z > g[x][y]) g[x][y] = g[y][x] = z;
      Max = max(Max, z);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) {
        tt.clear();
        dfs(i);
        ans = max(ans, (int)tt.size());
      }
    cout << ans << endl;
  }
  return 0;
}