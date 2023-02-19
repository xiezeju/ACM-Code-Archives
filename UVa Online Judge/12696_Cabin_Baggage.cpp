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
  int t, cnt = 0;
  cin >> t;
  while (t--) {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a > 56 || b > 45 || c > 25) && a + b + c > 125 || d > 7)
      cout << 0 << endl;
    else {
      cout << 1 << endl;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
