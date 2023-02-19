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

typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;

int ID(Set x) {
  if (IDcache.count(x)) return IDcache[x];
  Setcache.push_back(x);
  return IDcache[x] = Setcache.size() - 1;
}
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

int32_t main() {
#ifdef Online_Judge
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    stack<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string op;
      cin >> op;
      if (op[0] == 'P')
        s.push(ID(Set()));
      else if (op[0] == 'D')
        s.push(s.top());
      else {
        Set x1 = Setcache[s.top()];
        s.pop();
        Set x2 = Setcache[s.top()];
        s.pop();
        Set x;
        if (op[0] == 'U') set_union(ALL(x1), ALL(x2), INS(x));
        if (op[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
        if (op[0] == 'A') {
          x = x2;
          x.insert(ID(x1));
        }
        s.push(ID(x));
      }
      cout << Setcache[s.top()].size() << endl;
    }
    cout << "***" << endl;
  }

  return 0;
}