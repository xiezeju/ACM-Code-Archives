#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    if (n == 0) break;
    int sheet = ceil(1.0 * n / 4);
    int m = 4 * sheet;
    cout << "Printing order for " << n << " pages:" << endl;
    int cnt = 1, a[m + 1] = {};
    for (int i = 1; i <= m; i++) {
      if (i % 4 == 2 || i % 4 == 3) a[i] = cnt++;
      if (cnt > n) break;
    }

    for (int i = m; i >= 1; i--) {
      if (cnt <= n) {
        if (a[i] == 0) a[i] = cnt++;
      }
    }

    cnt = 1;
    for (int i = 1; i <= sheet; i++) {
      if (!a[cnt] && a[cnt + 1]) {
        cout << "Sheet " << i << ", front: "
             << "Blank"
             << ", " << a[++cnt] << endl;
        cnt++;
      } else
        cout << "Sheet " << i << ", front: " << a[cnt++] << ", " << a[cnt++]
             << endl;
      if (!(!a[cnt] && !a[cnt + 1])) {
        if (a[cnt] && !a[cnt + 1]) {
          cout << "Sheet " << i << ", back : " << a[cnt++] << ", "
               << "Blank" << endl;
          cnt++;
        } else
          cout << "Sheet " << i << ", back : " << a[cnt++] << ", " << a[cnt++]
               << endl;
      }
    }
  }
  return 0;
}
