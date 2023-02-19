#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int p[N + 1];

void init() {
  for (int i = 0; i <= N; i++) p[i] = i;
}

int find(int x) { return p[x] == x ? x : find(p[x]); }

void add(int i, int j) {
  int x = find(i);
  int y = find(j);

  if (x == y) return;
  p[y] = x;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    init();
    int n, m;
    cin >> n >> m;
    while (m--) {
      int a, b;
      cin >> a >> b;
      add(a, b);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i == find(i)) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}