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
    int n, b, h, w;
    while (cin >> n >> b >> h >> w) {
        int p, a;
        int ans = 1e9;
        for (int i = 1; i <= h; i++) {
            cin >> p;
            for (int j = 1; j <= w; j++) {
                cin >> a;
                if (a >= n) ans = min(ans, p * n);
            }
        }
        if (ans > b) cout << "stay home" << endl;
        else cout << ans << endl;
    }
    return 0;
}


