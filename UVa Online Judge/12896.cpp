#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 12;

char d[maxn][maxn]={{' '},{'.',',','?','\"'},{'a','b','c'},{'d','e','f'},
                    {'g','h','i'},{'j','k','l'},{'m','n','o'},
                    {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};


int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
      int l;cin>>l;
      int a[l+1],b[l+1];
      vector<char>c;
      for(int i = 0;i<l;i++) cin>>a[i];
      for(int i = 0;i<l;i++) cin>>b[i];
      for(int i = 0;i<l;i++){
        c.push_back(d[a[i]][b[i]-1]);
        cout<<c[i];
      }

      cout<<endl;


    }
    return 0;
}


