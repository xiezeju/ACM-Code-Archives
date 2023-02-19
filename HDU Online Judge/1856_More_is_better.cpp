#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e7 + 3;
int p[N], s[N], m, ans;

int find(int x) {
  if (p[x] == x) return p[x];
  return p[x] = find(p[x]);
}

void add(int i, int j) {
  int x = find(i);
  int y = find(j);
  if (x == y) return;
  p[y] = x;
  s[x] += s[y];
}

int main(void) {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  while (~scanf("%d", &m)) {
    for (int i = 1; i < N; i++) {
      p[i] = i;
      s[i] = 1;
    }
    int a, b;
    ans = 0;
    while (m--) {
      scanf("%d%d", &a, &b);
      add(a, b);
    }
    for (int i = 1; i < N; i++) {
      if (p[i] == i) ans = max(ans, s[i]);
    }
    cout << ans << endl;
  }
  return 0;
}