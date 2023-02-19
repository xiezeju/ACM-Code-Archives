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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  int n, m;
  while (cin >> n >> m) {
    int a = n * m, b = n + m;
    int c = gcd(a, b);
    printf("%d/%d\n", a / c, b / c);
  }

  return 0;
}