#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 2e6 + 10;

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    if (!n) break;
    int Max = 1;
    map<ll, int> sb;
    while (n--) {
      int a[5] = {};
      for (int i = 0; i < 5; i++) cin >> a[i];
      sort(a, a + 5);
      ll v = 0;
      for (int i = 0; i < 5; i++) {
        v *= 1000;
        v += a[i];
      }
      Max = max(Max, sb[v] += 1);
    }
    int ans = 0;
    auto it = sb.begin();
    for (; it != sb.end(); it++) {
      if (it->second == Max) ans += Max;
    }
    cout << ans << endl;
  }
  return 0;
}
