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
const int N = 1010 * 1010;

int to[N], v[N], w[N], ne[N], h[N];
int idx, d[N];
int C, R, st, ed, H;
bool vv[N];
queue<int> q;

void add(int x, int y, int hh, int ll) {
  to[++idx] = y, v[idx] = hh, w[idx] = ll;
  ne[idx] = h[x], h[x] = idx;
}

void SPFA(int limit) {
  memset(d, 0x3f, sizeof d);
  memset(vv, 0, sizeof vv);
  d[st] = 0;

  q.push(st);
  vv[st] = 1;
  while (q.size()) {
    int x = q.front();
    q.pop();
    vv[x] = 0;
    for (int i = h[x]; ~i; i = ne[i]) {
      int y = to[i], z = v[i], u = w[i];
      if (d[y] > d[x] + u && z >= limit) {
        d[y] = d[x] + u;
        if (!vv[y]) q.push(y), vv[y] = 1;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cases = 1;
  while (cin >> C >> R) {
    if (!C && !R) break;
    idx = 0;
    memset(h, -1, sizeof h);
    if (cases > 1) puts("");
    for (int i = 1; i <= R; i++) {
      int x, y, hh, ll;
      cin >> x >> y >> hh >> ll;
      if (hh == -1) hh = INF;
      add(x, y, hh, ll);
      add(y, x, hh, ll);
    }
    cin >> st >> ed >> H;
    int l = 0, r = H, mid, ans = INF;
    while (l < r) {
      mid = l + r + 1 >> 1;
      SPFA(mid);
      if (d[ed] != INF)
        l = mid, ans = d[ed];
      else
        r = mid - 1;
    }
    printf("Case %d:\n", cases++);
    if (ans == INF) {
      printf("cannot reach destination\n");
    } else {
      printf("maximum height = %d\n", l);
      printf("length of shortest route = %d\n", ans);
    }
  }

  return 0;
}