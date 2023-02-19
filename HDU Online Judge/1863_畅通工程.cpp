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
const int N = 110;
int g[N][N], d[N];
int n, m;
bool v[N];

int Prim() {
  int ans = 0;
  memset(d, 0x3f, sizeof d);
  memset(v, 0, sizeof v);
  d[1] = 0;

  for (int i = 0; i < n; i++) {
    int x = 0;
    for (int j = 1; j <= n; j++)
      if (!v[j] && (x == 0 || d[j] < d[x])) x = j;
    if (i && d[x] == INF) return INF;
    if (i) ans += d[x];
    v[x] = 1;

    for (int y = 1; y <= n; y++)
      if (!v[y]) d[y] = min(d[y], g[x][y]);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> m >> n) {
    if (!m) break;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++) g[i][i] = 0;
    for (int i = 1; i <= m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      g[x][y] = g[y][x] = min(g[x][y], z);
    }
    int w = Prim();
    if (w == INF)
      cout << "?" << endl;
    else
      cout << w << endl;
  }

  return 0;
}