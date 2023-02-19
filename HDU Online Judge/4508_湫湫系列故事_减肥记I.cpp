#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const long long LLINF = 4e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int N = 100010;
const int maxn = 110;
int dp[N];
int v[N], w[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) {
      cin >> v[i] >> w[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= n; i++)
      for (int j = w[i]; j <= m; j++) {
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      }
    cout << dp[m] << endl;
  }

  return 0;
}