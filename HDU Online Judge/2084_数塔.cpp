#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
#define INF 0x3f3f3f3f
// #define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const long long LLINF = 4e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int N = 110;

int a[N][N], dp[N][N];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= i; j++) cin >> a[i][j];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= i + 1; j++) dp[i][j] = -1e9;
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)
      for (int j = 1; j <= i; j++)
        dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
    int ans = -INF;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
  }

  return 0;
}