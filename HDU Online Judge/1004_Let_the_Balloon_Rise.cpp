#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n, n) {
    string s, ans;
    map<string, int> a;
    for (int i = 0; i < n; i++) {
      cin >> s;
      ++a[s];
    }
    int MAX = 0;
    for (auto i : a) {
      if (i.second > MAX) {
        MAX = i.second;
        ans = i.first;
      }
    }
    cout << ans << endl;
  }

  return 0;
}