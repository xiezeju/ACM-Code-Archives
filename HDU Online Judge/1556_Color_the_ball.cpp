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
const int N = 100010;

int a[N];
int sum[N];

int main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  while (cin >> t, t) {
    int l, r;
    memset(a, 0, sizeof(a));
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < t; i++) {
      cin >> l >> r;
      a[l] += 1;
      a[r + 1] -= 1;
    }
    for (int i = 1; i <= t; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= t; i++) {
      if (i != 1)
        cout << " " << sum[i];
      else
        cout << sum[i];
    }
    cout << endl;
  }

  return 0;
}