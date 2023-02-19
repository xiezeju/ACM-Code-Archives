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
const int N = 255;
int dp[N][N];
int s[5] = {1, 5, 10, 25, 50};

void solve() {
  dp[0][0] = 1;
  for (int i = 0; i < 5; i++)
    for (int j = 1; j < 101; j++)
      for (int k = s[i]; k < 251; k++) dp[k][j] += dp[k - s[i]][j - 1];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  int ans[251] = {};
  solve();
  for (int i = 0; i < 251; i++)
    for (int j = 0; j < 101; j++) ans[i] += dp[i][j];
  while (cin >> n) cout << ans[n] << endl;
  return 0;
}