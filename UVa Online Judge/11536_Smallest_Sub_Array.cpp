#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 1e6 + 10;

int a[maxn] = {}, f[maxn] = {};

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  int x = 1;
  while (t--) {
    memset(f, 0, sizeof f);
    int n, m, k;
    cin >> n >> m >> k;
    int ans = INF;
    a[1] = 1, a[2] = 2, a[3] = 3;

    for (int i = 4; i <= n; i++)
      a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;

    int l = 1, r = 1, cnt = 0;
    while (l <= r && r <= n) {
      if (cnt != k) {
        if (!f[a[r]] && a[r] <= k) cnt++;
        f[a[r++]]++;
      } else {
        ans = min(ans, r - l);
        f[a[l]]--;
        if (!f[a[l]] && a[l] <= k) cnt--;
        l++;
      }
      // cout<<l<<" "<<r<<endl;
    }
    if (ans == INF)
      printf("Case %d: sequence nai\n", x++);
    else
      printf("Case %d: %d\n", x++, ans);
  }
  return 0;
}
