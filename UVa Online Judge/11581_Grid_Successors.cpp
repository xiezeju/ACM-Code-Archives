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

int main() {
  ios::sync_with_stdio(false);
  int a[3][3], b[3][3];
  int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int n;
  cin >> n;
  while (n--) {
    int ans = 0;
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
      }
    while (1) {
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
          int sum = 0;
          if (j - 1 >= 0) sum += a[i][j - 1];
          if (i - 1 >= 0) sum += a[i - 1][j];
          if (j + 1 < 3) sum += a[i][j + 1];
          if (i + 1 < 3) sum += a[i + 1][j];
          b[i][j] = sum % 2;
        }
      if (memcmp(a, b, sizeof(a)) == 0) break;
      ans++;
      memcpy(a, b, sizeof(b));
    }
    cout << ans - 1 << endl;
  }
  return 0;
}
