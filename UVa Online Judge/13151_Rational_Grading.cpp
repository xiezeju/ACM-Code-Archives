#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 1e6 + 10;

char s[1500];

int main() {
  int t;
  while (scanf("%s %d", s, &t) == 2 && t != 0) {
    int x = 0, cnt = 0;
    if (s[0] == '0' && s[1] == 'x')
      sscanf(s, "%x", &x);
    else if (s[0] == '0')
      sscanf(s, "%o", &x);
    else
      sscanf(s, "%d", &x);
    while (t--) {
      string op;
      ll bns, ans;
      cin >> op >> bns;
      if (op == "++i") {
        ++x;
        if (bns == x)
          cnt++;
        else
          x = bns;
      } else if (op == "i++") {
        if (bns == x)
          cnt++;
        else
          x = bns;
        x++;
      } else if (op == "--i") {
        --x;
        if (bns == x)
          cnt++;
        else
          x = bns;
      } else if (op == "i--") {
        if (bns == x)
          cnt++;
        else
          x = bns;
        x--;
      } else if (op == "i") {
        if (bns == x)
          cnt++;
        else
          x = bns;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
