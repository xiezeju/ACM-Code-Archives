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
    int n;
    while(cin>>n){
      int a[n+1]={},d[n+1]={};
      int flag =0;
      for(int i=0;i<n;i++) {
        cin>>a[i];
        if(i)
        d[i] = abs(a[i]-a[i-1]);
      }
      sort(d+1,d+n);
      for(int i=1;i<=n-1;i++){
        if(d[i]!=i){
          flag=1;cout<<"Not jolly"<<endl;break;
        }

      }
      if(flag ==0) cout<<"Jolly"<<endl;
    }
    return 0;
}
