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
const int N = 200010;
int n, m;
int p[N], v[N];

int find(int x) {
  if (p[x] != x) {
    int t = p[x];
    p[x] = find(p[x]);
    v[x] += v[t];
  }
  return p[x];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n >> m) {
    int a, b, c;
    for (int i = 0; i <= n; i++) {
      p[i] = i;
      v[i] = 0;
    }
    int ans = 0;
    while (m--) {
      cin >> a >> b >> c;
      a--;
      int x = find(a);
      int y = find(b);
      if (x == y) {
        if (v[a] - v[b] != c) ans++;
      } else {
        p[x] = y;
        v[x] = -v[a] + v[b] + c;
      }
    }
    cout << ans << endl;
  }

  return 0;
}