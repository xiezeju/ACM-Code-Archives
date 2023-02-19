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

int a[N];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, m;
    cin >> n >> k >> m;
    n <= m ? cout << k : cout << (int)ceil(double(n * k) / m);
    cout << endl;
  }

  return 0;
}