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
    int a[10010]={};
    int q, l=0;
    while(cin>>q){
      a[++l]=q;
      sort(a+1,a+1+l);
      if(l&1) cout<<a[l+1>>1]<<endl;
      else cout<<(a[l>>1]+a[l/2+1])/2<<endl;
    }
    return 0;
}
