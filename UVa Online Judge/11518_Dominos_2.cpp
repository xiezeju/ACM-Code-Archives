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
const int N = 10010;
int to[N], ne[N], h[N];
int idx;
bool vis[N];

void add(int x, int y) {
  to[++idx] = y;
  ne[idx] = h[x], h[x] = idx;
}

void dfs(int x) {
  vis[x] = 1;
  for (int i = h[x]; ~i; i = ne[i])
    if (!vis[to[i]]) dfs(to[i]);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    idx = 0;
    memset(h, -1, sizeof h);
    memset(vis, 0, sizeof vis);
    int n, m, l;
    cin >> n >> m >> l;
    while (m--) {
      int x, y;
      cin >> x >> y;
      add(x, y);
    }
    while (l--) {
      int q;
      cin >> q;
      dfs(q);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
      if (vis[i]) ans++;
    cout << ans << endl;
  }
  return 0;
}
