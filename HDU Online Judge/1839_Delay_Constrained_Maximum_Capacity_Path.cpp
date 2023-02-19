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
const int N = 100010;

ll n, m, T, idx;
ll d[N], to[N], v[N], ti[N], ne[N], h[N];
bool vv[N];

void add(int x, int y, int z, int t) {
  to[++idx] = y, v[idx] = z, ti[idx] = t;
  ne[idx] = h[x], h[x] = idx;
}

bool Dijkstra(int xx) {
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
      int y = to[i], z = v[i], t = ti[i];
      if (!vv[y] && d[y] > d[x] + t && z >= xx) {
        d[y] = d[x] + t;
        q.push({d[y], y});
      }
    }
  }
  return d[n] <= T;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  while (x--) {
    idx = 0;
    memset(h, -1, sizeof h);

    cin >> n >> m >> T;
    ll l = INF, r = 0, mid;
    for (int i = 1; i <= m; i++) {
      ll a, b, c, d;
      cin >> a >> b >> c >> d;
      add(a, b, c, d);
      add(b, a, c, d);
      l = min(l, c);
      r = max(r, c);
    }
    while (l < r) {
      mid = l + r + 1 >> 1;
      if (Dijkstra(mid))
        l = mid;
      else
        r = mid - 1;
    }
    cout << r << endl;
  }

  return 0;
}
