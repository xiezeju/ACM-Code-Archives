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
    string s;
    while (cin >> s) {
        int last = 0, ans = 0, flag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'X') {
                if (!flag) ans = max(ans, i - last-1), flag = 1;
                else
                    ans = max(ans, (i - last - 2) / 2);
                last = i;
            }
            if(i==s.size()-1&&s[i]=='.') ans = max(ans,i-last-1);
        }
        cout << ans << endl;
    }
    return 0;
}
