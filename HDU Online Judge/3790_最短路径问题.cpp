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

int n, m, idx;
int to[N], v[N], pay[N], ne[N],
    h[N];  // 链式前向星要多承载一个花销的属性, 因此新增了数组pay
int d[N], p[N];
bool vv[N];

struct sb {
  int d, p, idx;
  sb(int a, int b, int c) : d(a), p(b), idx(c) {}  // 构造函数, 默认赋值为0
  friend bool operator>(sb a, sb b) {  // 友元重载大于号以便生成小根堆
    if (a.d == b.d) return a.p > b.p;
    return a.d > b.d;
  }
};

void add(int x, int y, int z, int w) {
  to[++idx] = y, v[idx] = z, pay[idx] = w;
  ne[idx] = h[x], h[x] = idx;
}

void dijkstra(int s) {
  memset(d, 0x3f, sizeof d);
  memset(p, 0x3f, sizeof p);
  memset(vv, 0, sizeof vv);
  d[s] = 0;
  p[s] = 0;

  priority_queue<sb, vector<sb>, greater<sb>> q;
  q.push({0, 0, s});

  while (q.size()) {
    int x = q.top().idx;
    q.pop();
    if (vv[x]) continue;
    vv[x] = 1;

    for (int i = h[x]; ~i; i = ne[i]) {
      int y = to[i], z = v[i], w = pay[i];
      if (d[y] > d[x] + z) {
        d[y] = d[x] + z;
        p[y] = p[x] + w;
        q.push({d[y], p[y], y});
      } else if (d[y] == d[x] + z) {
        if (p[y] > p[x] + w) {
          p[y] = p[x] + w;
          q.push({d[y], p[y], y});
        }
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> m) {
    if (!n && !m) break;

    idx = 0;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= m; i++) {
      int x, y, z, w;
      cin >> x >> y >> z >> w;
      add(x, y, z, w);
      add(y, x, z, w);
    }

    int s, t;
    cin >> s >> t;

    dijkstra(s);
    cout << d[t] << " " << p[t] << endl;
  }

  return 0;
}