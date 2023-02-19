#include <bits/stdc++.h>
using namespace std;

int32_t main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, l, r;
  set<string> a;
  while (cin >> s) a.insert(s);
  for (auto curent_string : a) {
    for (int j = 1; j < curent_string.size(); j++) {
      l.assign(curent_string, 0, j);
      if (a.count(l)) {
        r.assign(curent_string, j, curent_string.size() - j);
        if (a.count(r)) {
          cout << curent_string << endl;
          break;
        }
      }
    }
  }

  return 0;
}