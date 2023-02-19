#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
#define INF 0x3f3f3f3f
// #define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const long long LLINF = 4e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int N = 110;

string mm(string s, int x) {
  reverse(s.begin(), s.end());
  int t = 0;
  for (int i = 0; i < s.size(); i++) {
    t = (s[i] - '0') * x + t;
    s[i] = (t % 10 + '0');
    t /= 10;
  }
  while (t) {
    s += (t % 10 + '0');
    t /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}

int main() {
  int n;
  while (cin >> n) {
    string ss = "1";
    for (int i = 1; i <= n; i++) ss = mm(ss, i);
    cout << ss << endl;
  }

  return 0;
}