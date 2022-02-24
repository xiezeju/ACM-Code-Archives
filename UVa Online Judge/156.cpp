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
//#define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const long long LLINF = 4e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int N = 10010;

map<string, int> ss;
vector<string> a;

string pre(const string &s)
{
    string ans = s;
    for (int i = 0; i < ans.size(); i++)
        ans[i] = tolower(ans[i]);
    sort(ans.begin(), ans.end());
    return ans;
}

int32_t main()
{

#ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s)
    {
        if (s == "#")
            break;
        a.push_back(s);
        string r = pre(s);
        if (!ss.count(r))
            ss[r] = 0;
        ++ss[r];
    }
    vector<string> ans;
    for (int i = 0; i < a.size(); i++)
        if (ss[pre(a[i])] == 1)
            ans.push_back(a[i]);
    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << endl;

    return 0;
}