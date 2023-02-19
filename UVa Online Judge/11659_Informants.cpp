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
const int N = 300;

bool trust[21];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a;
  while (cin >> n >> a) {
    if (!a && !n) break;
    int cnt = 0;  // 统计不可靠的人数
    memset(trust, 1, sizeof trust);
    for (int i = 1; i <= a; i++) {
      int x, y;
      cin >> x >> y;
      if (y < 0) {
        if (trust[y * (-1)]) {
          trust[y * (-1)] = 0;
          cnt++;
        }
      }
    }
    cout << n - cnt << endl;
  }
  return 0;
}
