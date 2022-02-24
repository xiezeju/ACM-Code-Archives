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




int ch[130];
char str[10005];

int main() {
    int n, k, val, m, len, i;
    long long sum;
    char c;
    scanf("%d", &n);
    while (n--) {
        memset(ch, 0, sizeof(ch));
        scanf("%d\n", &k);
        while (k--) {
            c = getchar();
            scanf("%d\n", &val);
            ch[c] = val;
        }
        scanf("%d\n", &m);
        sum = 0;
        while (m--) {
            gets(str);
            len = strlen(str);
            for (i = 0; i < len; ++i)
                sum += ch[str[i]];
        }
        printf("%.2f$\n", (double)sum / 100);
    }
    return 0;
}

//´ð°¸2
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

int main()
{

#ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        map<char, double> a;
        int m;
        cin >> m;
        while (m--)
        {
            char b;
            double c;
            cin >> b >> c;
            a[b] = c;
        }
        double ans = 0;
        int n;
        cin >> n;
        cin.ignore();
        while (n--)
        {
            string s;
            getline(cin, s);
            for (int i = 0; i < s.size(); i++)
                ans += a[s[i]];
        }
        printf("%.2lf$\n", ans / 100);
    }

    return 0;
}