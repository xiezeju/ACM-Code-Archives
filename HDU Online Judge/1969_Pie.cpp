#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const long long LLINF = 4e18;
const double EPS = 1e-5;
double pi = acos(-1.0);

int n, f;
double a[10010];

bool check(double x) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += int(a[i] / x);
  }
  return cnt >= f;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> f;
    double l = 0, r = 0, mid;
    for (int i = 1; i <= n; i++) {
      int q;
      cin >> q;
      a[i] = q * q * pi;
      r += a[i];
    }
    f++;
    r /= f;
    while (r - l > EPS) {
      mid = (l + r) / 2;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    printf("%.4lf\n", mid);
  }

  return 0;
}