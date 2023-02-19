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
  int t;
  cin >> t;
  int x = 1;
  while (t--) {
    int m, n;
    cin >> m >> n;
    cin.ignore();
    set<string> sb;
    string s1[1510], s2[1510];
    for (int i = 0; i < m; i++) getline(cin, s1[i]);
    for (int i = 0; i < n; i++) getline(cin, s2[i]);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) sb.insert(s1[i] + s2[j]);
    cout << "Case " << x++ << ": " << sb.size() << endl;
  }
  return 0;
}
