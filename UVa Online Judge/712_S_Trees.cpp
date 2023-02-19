#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int n;
char T[N];
int32_t main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);

  int k = 1;
  while (cin >> n, n) {
    cout << "S-Tree #" << k++ << ":" << endl;
    string s;
    cin.ignore();
    getline(cin, s);
    getline(cin, s);

    int cnt = pow(2, n);
    for (int i = 0; i < s.size(); i++) T[cnt++] = s[i];

    string ans;
    int t;
    cin >> t;
    while (t--) {
      int u = 1;
      string a;
      cin >> a;
      for (int i = 0; i < a.size(); i++) {
        u = a[i] == '0' ? (u << 1) : (u << 1) + 1;
      }
      ans = ans + T[u];
    }
    cout << ans << endl << endl;
  }

  return 0;
}