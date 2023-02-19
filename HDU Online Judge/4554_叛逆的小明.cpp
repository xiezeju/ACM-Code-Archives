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

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    int n = x + y >> 1;
    int m = x - y >> 1;
    x = y = 0;
    while (n) {
      x = x * 10 + n % 10;
      n /= 10;
    }
    while (m) {
      y = y * 10 + m % 10;
      m /= 10;
    }
    cout << x + y << " " << x - y << endl;
  }
  return 0;
}