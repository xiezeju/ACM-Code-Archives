#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 1e5 + 10;
int a[maxn] = {};

ll sg(ll a) {
    ll v = 0;
    while (a != 0) {
        v += a % 10;
        a /= 10;
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    ll a;
    while (cin >> a) {
        ll ans = 0;
        if (a == 0)break;
        ans = sg(a);
        while (ans >= 10) ans = sg(ans);
        cout << ans << endl;
    }
    return 0;
}

