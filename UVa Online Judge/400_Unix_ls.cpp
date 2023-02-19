#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
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
const int N = 10010;

void print(const string &s, int len, char extra) {
  cout << s;
  for (int i = 0; i < len - s.size(); i++) cout << extra;
}

int32_t main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  while (cin >> t) {
    int M = 0;
    int n = t;

    vector<string> a;
    string s;
    while (t--) {
      cin >> s;
      M = max(M, (int)s.size());
      a.push_back(s);
    }

    int cols = (60 - M) / (M + 2) + 1;
    int rows = (n - 1) / cols + 1;
    print("", 60, '-');
    cout << endl;
    sort(a.begin(), a.end());
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int idx = c * rows + r;
        if (idx < n) print(a[idx], c == cols - 1 ? M : M + 2, ' ');
      }
      cout << endl;
    }
  }

  return 0;
}