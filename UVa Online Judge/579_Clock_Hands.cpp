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
  int h, m;
  char c;
  while (cin >> h >> c >> m) {
    if (h == 0 && m == 0) break;
    double ans;
    ans = abs(h * 1.0 / 12 * 360 + m * 1.0 / 60 * 30 - m * 1.0 / 60 * 360);
    if (ans > 180) ans = 360 - ans;
    printf("%.3lf\n", ans);
  }
  return 0;
}
