#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(false);
  int x, y, z, n, m;
  while (~scanf("%d", &n))
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &m);
      x = y = 0;
      for (int j = 0; j < m; ++j) {
        scanf("%d", &z);
        x += (z / 30 + 1) * 10;
        y += (z / 60 + 1) * 15;
      }
      printf("Case %d: ", i);
      if (x < y)
        printf("Mile %d\n", x);
      else if (x > y)
        printf("Juice %d\n", y);
      else
        printf("Mile Juice %d\n", x);
    }
  return 0;
}
