#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(false);
  int n1, n2, ans, bans;
  char c1, d;
  string c2;
  int cnt = 0;
  while (cin >> n1 >> c1 >> n2 >> d >> c2) {
    stringstream ss;
    if (c2 == "?") continue;
    if (c1 == '+')
      ans = n1 + n2;
    else
      ans = n1 - n2;
    ss << c2;
    ss >> bans;
    if (bans == ans) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
