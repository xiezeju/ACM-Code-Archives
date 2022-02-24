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
    int t;cin>>t;
    int x=1;
    while(t--){
      char c;
      int h[5]={},m[5]={},s[5]={};
      for(int i = 1;i<=4;i++){
        cin>>h[i]>>c>>m[i];
        s[i] = 60*h[i]+m[i];
      }
      if(s[4]<s[1]||s[3]>s[2])
        printf("Case %d: Hits Meeting\n",x++);
      else printf("Case %d: Mrs Meeting\n",x++);
    }
    return 0;
}


