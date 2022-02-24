#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
const int INF = 0x3f3f3f3f;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 30010;

int l;
bool VIS[55];

void vis(int i, int j) {
    if (i - j >= 0 && i - j <= l)
        VIS[i - j] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    int x = 1;
    while (t--) {
        string s; cin >> s;
        l = s.size();
        memset(VIS, 0, sizeof VIS);
        for (int i = 0; i < l; i++) {
            if (s[i] == 'B') vis(i, 0), vis(i, 1), vis(i, 2);
            else if (s[i] == 'D') vis(i, 0);
            else if (s[i] == 'S') vis(i, 0), vis(i, 1), vis(i, -1);
        }
        int ans=0;
        for(int i=0;i<l;i++){
          if(!VIS[i]) ans++;
        }
        cout<<"Case "<<x++<<": "<<ans<<endl;
    }
    return 0;
}
