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

int main() {
  ios::sync_with_stdio(false);
  string a =
      "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"
      "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>? ";
  string b =
      "`123qjlmfp/"
      "[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*("
      "AEHTDCK_)ZX<INWVG\" ";
  char m[128];
  for (int i = 0; a[i]; i++) m[a[i]] = b[i];
  string s;
  while (getline(cin, s)) {
    for (char c : s) cout << m[c];
    cout << endl;
  }
  return 0;
}
