#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 2e6 + 10;

int a[128] = {};

int main() {
  ios::sync_with_stdio(false);
  string s;
  a['B'] = a['F'] = a['P'] = a['V'] = 1;
  a['C'] = a['G'] = a['J'] = a['K'] = a['Q'] = a['S'] = a['X'] = a['Z'] = 2;
  a['D'] = a['T'] = 3;
  a['L'] = 4;
  a['M'] = a['N'] = 5;
  a['R'] = 6;

  while (getline(cin, s)) {
    if (a[s[0]]) cout << a[s[0]];
    for (int i = 1; i < s.size(); i++) {
      if (a[s[i]] && s[i] != s[i - 1] && a[s[i]] != a[s[i - 1]])
        cout << a[s[i]];
    }
    cout << endl;
  }
  return 0;
}
