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

int main() {
  ios::sync_with_stdio(false);
  string s;

  while (getline(cin, s)) {
    int a[128] = {}, ans = 0;
    for (int i = 0; i < s.size(); i++) a[(int)s[i]]++;
    for (int i = 'A'; i <= 'z'; i++)
      if (a[i] > ans) ans = a[i];
    for (int i = 'A'; i < 'z'; i++)
      if (a[i] == ans) cout << (char)i;
    cout << " " << ans << endl;
  }
  return 0;
}
