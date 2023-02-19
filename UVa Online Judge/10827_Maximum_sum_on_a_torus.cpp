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
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
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
const int N = 10010;

int n;
int a[155][155];
int s[155][155];

int main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
        a[i][j + n] = a[i + n][j] = a[i + n][j + n] = a[i][j];
      }
    for (int i = 1; i <= 2 * n; i++)
      for (int j = 1; j <= 2 * n; j++)
        s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
    int ans = -1e9;
    for (int x = 1; x <= n; x++)
      for (int y = 1; y <= n; y++)
        for (int i = 0; i < n; i++)
          for (int j = 0; j < n; j++)
            ans = max(ans, s[x + i][y + j] - s[x - 1][y + j] - s[x + i][y - 1] +
                               s[x - 1][y - 1]);
    cout << ans << endl;
  }
  return 0;
}