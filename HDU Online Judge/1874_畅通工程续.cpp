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
const int N = 1010;

int to[N], v[N], ne[N], h[N];
int idx, n, m;
int d[N];
bool vv[N];
queue<int> q;

void add(int x, int y, int z) {
  to[idx] = y, v[idx] = z;
  ne[idx] = h[x], h[x] = idx++;
}

void SPFA(int s) {
  memset(d, 0x3f, sizeof d);
  memset(vv, 0, sizeof vv);
  d[s] = 0;

  q.push(s);
  vv[s] = 1;

  while (q.size()) {
    int x = q.front();
    q.pop();
    vv[x] = 0;

    for (int i = h[x]; ~i; i = ne[i]) {
      int y = to[i], z = v[i];
      if (d[y] > d[x] + z) {
        d[y] = d[x] + z;
        if (!vv[y]) q.push(y), vv[y] = 1;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> m) {
    idx = 0;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      add(x, y, z);
      add(y, x, z);
    }
    int s, t;
    cin >> s >> t;
    SPFA(s);
    if (d[t] == INF)
      cout << -1 << endl;
    else
      cout << d[t] << endl;
  }

  return 0;
}
