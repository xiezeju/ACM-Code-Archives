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
const int N = 20010;
int n, m, p[N];
int g[N][N], d[N];

struct sb {
  int x, y, z;
  friend bool operator<(sb a, sb b) { return a.z < b.z; }
} e[N];

int find(int x) { return p[x] == x ? x : find(p[x]); }

int Kruskal() {
  int ans = 0;
  sort(e + 1, e + 1 + m);

  for (int i = 1; i <= m; i++) {
    int x = find(e[i].x);
    int y = find(e[i].y);
    if (x == y) continue;
    p[x] = y;
    ans += e[i].z;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n) {
    m = 0;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        cin >> g[i][j];
        if (j > i) e[++m] = {i, j, g[i][j]};
      }

    int q;
    cin >> q;
    while (q--) {
      int a, b;
      cin >> a >> b;
      int x = find(a);
      int y = find(b);
      if (x == y) continue;
      p[x] = y;
    }
    int w = Kruskal();
    cout << w << endl;
  }

  return 0;
}