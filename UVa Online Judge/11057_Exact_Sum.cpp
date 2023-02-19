#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
int a[10010];
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int q;
    cin >> q;

    int l = 0, r = n - 1, s, b;
    while (l < r) {
      if (a[l] + a[r] == q) {
        s = l++, b = r--;
      } else if (a[l] + a[r] < q)
        l++;
      else
        r--;
    }
    printf("Peter should buy books whose prices are %d and %d.\n\n", a[s],
           a[b]);
  }

  return 0;
}
