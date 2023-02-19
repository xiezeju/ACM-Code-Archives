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
const int N = 10010;
int n, q, p[N], s[N], v[N];

int find(int x) {
  if (p[x] == x)
    return x;
  else {
    int t = p[x];
    p[x] = find(p[x]);
    v[x] += v[t];
    return p[x];
  }
}
void add(int i, int j) {
  int x = find(i);
  int y = find(j);
  if (x == y) return;
  p[x] = y;
  v[x]++;
  s[y] += s[x];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  int g = 1;
  while (t--) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      s[i] = 1;
      v[i] = 0;
    }
    printf("Case %d:\n", g++);
    while (q--) {
      char c;
      cin >> c;
      int x, y;
      if (c == 'T') {
        cin >> x >> y;
        add(x, y);
      } else if (c == 'Q') {
        cin >> x;
        int w = find(x);
        printf("%d %d %d\n", w, s[w], v[x]);
      }
    }
  }

  return 0;
}