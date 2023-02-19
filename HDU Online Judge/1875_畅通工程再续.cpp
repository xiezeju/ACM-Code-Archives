#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const long long LLINF = 4e18;
const double EPS = 1e-7;
const int N = 15000;

int p[N], n, m;

struct sb {
  int x, y;
  double z;
  friend bool operator<(sb a, sb b) { return a.z < b.z; }
} e[N];

int find(int x) { return p[x] == x ? x : find(p[x]); }

double kruskal() {
  double ans = 0, cnt = 0;
  sort(e, e + m);
  for (int i = 0; i <= n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    int x = find(e[i].x);
    int y = find(e[i].y);
    if (x == y) continue;
    p[x] = y;
    ans += e[i].z;
    cnt++;
  }
  if (cnt < n - 1) return -1;
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int idx = 0;
    int x, y;
    cin >> n;
    vii a;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      a.push_back({x, y});
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double aa = a[i].first - a[j].first;
        double bb = a[i].second - a[j].second;
        double dis = hypot(aa, bb);
        if (dis > 10 - EPS && dis < EPS + 1000) {
          e[idx++] = {i, j, dis};
        }
      }
    }
    m = idx;
    double w = kruskal();
    if (w < 0)
      puts("oh!");
    else
      printf("%.1lf\n", w * 100);
  }

  return 0;
}