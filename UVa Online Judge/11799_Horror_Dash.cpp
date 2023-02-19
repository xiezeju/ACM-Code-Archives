#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const int LLINF = 4e18;
const double EPS = 1e-9;

int main() {
  int t, x = 1;
  cin >> t;
  while (t--) {
    int n, Max = 0;
    cin >> n;
    int a[n] = {};
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > Max) Max = a[i];
    }
    cout << "Case " << x++ << ": " << Max << endl;
  }
}
