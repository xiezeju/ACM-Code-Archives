#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

const int N = 10010;

int p[N], n, m;

struct edge {
  int x, y, z;
  friend bool operator<(edge a, edge b) { return a.z < b.z; }
} e[N];

int find(int x) { return p[x] == x ? x : find(p[x]); }

int kruskal() {
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
    if (!n) break;

    m = n * (n - 1) / 2;
    int x, y, z;

    for (int i = 0; i <= n; i++) p[i] = i;

    for (int i = 1; i <= m; i++) {
      cin >> x >> y >> z;
      e[i] = {x, y, z};
    }
    int w = kruskal();
    if (w == INF)
      cout << "impossible" << endl;
    else
      cout << w << endl;
  }

  return 0;
}