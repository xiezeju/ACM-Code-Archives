#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
const int N = 2500;

int p[N], n, m;

struct sb {
  int x, y, z;
  friend bool operator<(sb a, sb b) { return a.z < b.z; }
} e[N];

int find(int x) { return p[x] == x ? x : find(p[x]); }

int kruskal() {
  int ans = 0;
  sort(e + 1, e + 1 + m);
  for (int i = 0; i <= n; i++) p[i] = i;
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
  while (cin >> n && n) {
    m = 0;
    char a, c;
    int b, q;
    for (int i = 1; i < n; i++) {
      cin >> a >> b;
      while (b--) {
        cin >> c >> q;
        e[++m] = {a - 'A', c - 'A', q};
      }
    }
    int w = kruskal();
    cout << w << endl;
  }

  return 0;
}