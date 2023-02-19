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

ll quickpow(ll k) {
  ll a = 1, b = k, base = k;
  while (b) {
    if (b & 1) a = a * base % 10;
    base = base * base % 10;
    b >>= 1;
  }
  return a;
}

int main() {
  int t;
  cin >> t;
  ll k;
  while (t--) {
    cin >> k;
    cout << quickpow(k) << endl;
  }

  return 0;
}