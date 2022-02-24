#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;




int main() {
    ios::sync_with_stdio(false);
    int c; cin >> c;
    int x = 1;
    while (c--) {
        string s, t; cin >> s >> t;
        int ans = 0;
        int sz, so, sw, tz, to;
        sz = so = sw = tz = to = 0;
        int l = s.size();
        for (int i = 0; i < l; i++) {
            if (s[i] == '?') sw++;
            if (s[i] == '0') sz++;
            if (s[i] == '1') so++;
            if (t[i] == '0') tz++;
            if (t[i] == '1') to++;
        }
        if (so > to || so + sw < to)
            cout << "Case " << x++ << ": " << -1 << endl;
        else {
            for (int i = 0; i < l; i++) {
                if (s[i] == '?') {
                    if (t[i] == '0') {
                        if (sz < tz) s[i] = '0', sz++, ans++;
                        else s[i] = '1', so++, ans++;
                    } else if (t[i] == '1') {
                        if (so < to) s[i] = '1', so++, ans++;
                        else s[i] = '0', sz++, ans++;
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < l; i++) {
                if (s[i] != t[i]) cnt++;
            }
            ans += cnt / 2;
            cout << "Case " << x++ << ": " << ans << endl;
        }
    }
    return 0;
}



