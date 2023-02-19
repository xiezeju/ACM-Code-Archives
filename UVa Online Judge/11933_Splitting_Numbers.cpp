#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 2e6 + 10;

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    if (n == 0) break;
    int b = 0, cnt = 0;
    for (int i = 0; i < 32; i++)
      if ((1 << i) & n && (cnt++) & 1) b += 1 << i;
    cout << n - b << " " << b << endl;
  }
  return 0;
}
