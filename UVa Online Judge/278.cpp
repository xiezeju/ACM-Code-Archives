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
    int t; cin >> t;
    while (t--) {
        char c;
        int m, n;
        cin >> c >> m >> n;
        if (c == 'r')
            cout << min(m, n) << endl;
        if (c == 'k') {
            //马分一行，两行，和两行以上考虑，一行就能全放，两行就隔一个田字格放，三行以上就每个马隔一个位置放。
            if (m == 1 || n == 1) cout << max(m, n) << endl;
            else if (n == 2)cout << m / 2 * 2 + m % 2 * 2 << endl;
            else if (m == 2)cout << n / 2 * 2 + n % 2 * 2 << endl;
            else cout << (n * m + 1) / 2 << endl;
        }
        if (c == 'Q')
            cout << min(m, n) << endl;
        if (c == 'K')
            cout << (n + 1) / 2 * ((m + 1) / 2) << endl;
    }
    return 0;
}


