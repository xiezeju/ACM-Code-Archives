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

int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    if (!n) break;
    int j = 0, k;
    for (k = 1;; k++) {
      for (int i = 1; i < n; i++) j = (j + k) % i;
      if (j == 11) break;
    }
    cout << k << endl;
  }
  return 0;
}
