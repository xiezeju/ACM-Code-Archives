#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int MAXN = 1e6 + 10;

int p, a, b, c, d, n;
double price[MAXN];
double ans, maxn;

int main() {
  ios::sync_with_stdio(false);
  while (cin >> p >> a >> b >> c >> d >> n) {
    ans = 0;
    for (int i = 1; i <= n; i++)
      price[i] = p * (sin(a * i + b) + cos(c * i + d) + 2);
    maxn = price[1];
    for (int i = 2; i <= n; i++) {
      if (price[i] > maxn)
        maxn = price[i];
      else
        ans = max(ans, maxn - price[i]);
    }
    printf("%.6lf\n", ans);
  }
  return 0;
}
