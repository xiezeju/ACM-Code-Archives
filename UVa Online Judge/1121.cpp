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

int a[maxn],s[maxn]={};

int main() {
    ios::sync_with_stdio(false);
    int n, S;
    while (cin>>n>>S) {
        int cnt = 0, ans = 1e9;
        for (int i = 1; i <= n; i++) {
          cin >> a[i];
          s[i] = s[i-1]+a[i];//用前缀和处理一下
        }

        int l=1,r=1;//设置左右指针
        while (l<=r&&r<=n) {
            if(s[r]-s[l-1]<S) r++;
            else {
                ans = min(ans,r-l+1);
                l++;
            }
        }
        ans = ans==1e9? 0 : ans;
        cout << ans << endl;
    }
    return 0;
}
