#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 2e6 + 10;

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    string s;
    cin >> s;
    multiset<string> a;
    for (int i = 0; i <= s.size() - n; i++) {
      string sub;
      sub = s.substr(i, n);
      a.insert(sub);
    }
    int Max = 0;
    auto it = a.begin();
    for (it; it != a.end(); it++)
      if (a.count(*it) > Max) {
        Max = a.count(*it);
        s.clear();
        s += *it;
      }
    cout << s << endl;
  }
  return 0;
}
