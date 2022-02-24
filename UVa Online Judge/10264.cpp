#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 2e6 + 10;

int w[1<<15]={},p[1<<15]={};

int main() {
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
      int x = 1<<n;
      for(int i=0;i<x;i++) {cin>>w[i];p[i]=0;}
      for(int i=0;i<x;i++)
        for(int j=0;j<n;j++) p[i]+=w[i^(1<<j)];
      int ans = 0;
      for(int i=0;i<x;i++)
        for(int j=0;j<n;j++){
          if(ans<p[i]+p[i^(1<<j)])
            ans=p[i]+p[i^(1<<j)];
        }
      cout<<ans<<endl;
    }
    return 0;
}
