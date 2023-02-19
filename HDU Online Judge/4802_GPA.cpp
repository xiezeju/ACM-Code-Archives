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

map<string, double> s;

int main() {
  s["A"] = 4.0, s["A-"] = 3.7, s["B+"] = 3.3, s["B"] = 3.0, s["B-"] = 2.7,
  s["C+"] = 2.3, s["C"] = 2.0, s["C-"] = 1.7, s["D"] = 1.3, s["D-"] = 1.0,
  s["F"] = 0;
  int n;
  while (cin >> n) {
    string ss;
    double a, sum = 0;
    double cnt = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a >> ss;
      if (ss != "P" && ss != "N") {
        sum += a * s[ss];
        cnt += a;
      }
    }
    if (cnt)
      printf("%.2lf\n", sum / cnt);
    else
      cout << "0.00" << endl;
  }

  return 0;
}