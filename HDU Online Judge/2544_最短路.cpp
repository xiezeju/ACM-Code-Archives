#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 10010;
int to[N], v[N], ne[N], h[N];
int idx, n, m;
;
int d[N];
bool vv[N];

void add(int x, int y, int z) {
  to[++idx] = y, v[idx] = z;
  ne[idx] = h[x], h[x] = idx;
}

void dijkstra() {
  memset(d, 0x3f, sizeof d);
  memset(vv, 0, sizeof vv);
  d[1] = 0;

  priority_queue<ii, vii, greater<ii>> q;
  q.push({0, 1});

  while (q.size()) {
    int x = q.top().second;
    q.pop();
    if (vv[x]) continue;
    vv[x] = 1;

    for (int i = h[x]; ~i; i = ne[i]) {
      int y = to[i], z = v[i];
      if (d[y] > d[x] + z) {
        d[y] = d[x] + z;
        q.push({d[y], y});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> m) {
    if (!n && !m) break;

    idx = 0;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      add(x, y, z);
      add(y, x, z);
    }
    dijkstra();
    cout << d[n] << endl;
  }

  return 0;
}