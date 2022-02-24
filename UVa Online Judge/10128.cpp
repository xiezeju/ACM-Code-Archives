#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
const int INF = 0x3f3f3f3f;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 20;

ll dp[N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        memset(dp, 0, sizeof dp);
        dp[1][1][1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
                for (int k = 1; k <= i-j+1; k++)
                    dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + (i - 2) * dp[i - 1][j][k];
        cout << dp[n][a][b] << endl;
    }
    return 0;
}
