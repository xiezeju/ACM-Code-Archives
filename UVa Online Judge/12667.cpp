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

struct sb {
    int x, y;
    char s;
    sb(int nx=0,int ny=0){x=nx,y=ny;}
} q[20];

bool vis[110][20];

int main() {
    ios::sync_with_stdio(false);
    int n, t, m;
    while (cin >> n >> t >> m) {
        int a, b;
        char c;
        string d;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c >> d;
            int r = c - 'A';
            if (d == "Yes"&&!vis[b][r]) {
                q[r].s = c;
                q[r].x = a;
                q[r].y = b;
                vis[b][r]=1;
            }
        }
        for (int i = 0; i < n; i++) {
            char c ='A'+i;
            if (q[i].y == 0)
                cout << c << " - -" << endl;
            else cout << c << " " << q[i].x << " " << q[i].y << endl;
        }
    }
    return 0;
}
