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

int a[maxn];
int f[maxn];
int b[maxn];
int main() {
  int n;
  while (cin >> n) {
    if (n == 0) break;
    int r = 0, c = 1e9;
    memset(f, 0, sizeof f);

    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      r = max(r, a[i]);
      c = min(c, a[i]);
    }
    for (int i = 0; i < n; i++) f[a[i] - c]++;
    for (int i = 1; i < r; i++) f[i] += f[i - 1];
    for (int i = n - 1; i >= 0; i--) {
      b[f[a[i] - c] - 1] = a[i];
      f[a[i] - c]--;
    }
    for (int i = 0; i < n; i++) {
      if (i != n - 1)
        cout << b[i] << " ";
      else
        cout << b[i] << endl;
    }
  }
  return 0;
}
