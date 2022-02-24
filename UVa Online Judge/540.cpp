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
const int N = 1010;

int32_t main()
{

#ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, k = 0;
    while (cin >> t, t)
    {
        printf("Scenario #%d\n", ++k);

        map<int, int> team;
        for (int i = 0; i < t; i++)
        {
            int n, x;
            cin >> n;
            while (n--)
            {
                cin >> x;
                team[x] = i;
            }
        }

        queue<int> q, q2[N];
        for (;;)
        {
            int x;
            string s;
            cin >> s;
            if (s[0] == 'S')
                break;
            else if (s[0] == 'D')
            {
                int t = q.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if (q2[t].empty())
                    q.pop();
            }
            else if (s[0] == 'E')
            {
                cin >> x;
                int t = team[x];
                if (q2[t].empty())
                    q.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");
    }

    return 0;
}