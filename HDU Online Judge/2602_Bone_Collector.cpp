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
const int N = 1010;
int v[N], w[N];
int dp[N][N];
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= m; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= w[i]) {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
      }
    cout << dp[n][m] << endl;
  }

  return 0;
}