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

int find(int n) {
  int cnt = 0;
  while (n) cnt++, n >>= 1;
  return cnt;
}

int jos(int n) {
  int len = find(n);
  n ^= (1 << (len - 1));
  n <<= 1;
  n |= 1;
  return n;
}

int main() {
  int t, caseno = 0, n, survivor;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int cnt = 0;
    for (;;) {
      cnt++;
      if ((survivor = jos(n)) == n) break;
      n = survivor;
    }
    printf("Case %d: %d %d\n", ++caseno, cnt - 1, n);
  }
  return 0;
}
