#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 1e5 + 10;
int a[maxn] = {};

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> a[0] >> a[1];
    int ans = a[0] - a[1], Max = a[0] > a[1] ? a[0] : a[1];
    for (int i = 2; i < n; i++) {
      cin >> a[i];
      ans = max(ans, Max - a[i]);
      Max = max(Max, a[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
