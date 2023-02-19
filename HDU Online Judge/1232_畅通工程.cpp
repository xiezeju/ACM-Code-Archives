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

int n, m, p[N], cnt;

int find(int x) { return p[x] == x ? x : find(p[x]); }

void add(int i, int j) {
  if (i > j) return add(j, i);
  int x = find(i);
  int y = find(j);
  if (x == y) return;
  p[y] = x;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n >> m) {
    if (!n) break;
    for (int i = 1; i <= n; i++) p[i] = i;
    cnt = 0;
    for (int k = 1; k <= m; k++) {
      int i, j;
      cin >> i >> j;
      add(i, j);
    }
    for (int i = 1; i <= n; i++) {
      if (p[i] == i) cnt++;
    }
    cout << cnt - 1 << endl;
  }

  return 0;
}