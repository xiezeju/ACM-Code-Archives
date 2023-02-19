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
const int N = 1010;

int js(int n) {
  int a = n, cnt = 0;
  while (a) {
    a /= 2;
    cnt++;
  }
  n = ((n << 1) + 1) ^ (1 << cnt);
  return n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    int ans = 0;
    while (1) {
      int j;
      if ((j = js(n)) == n) {
        ans += 2 * j;
        break;
      } else {
        ans += n - j;
        n = j;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
