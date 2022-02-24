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

struct sb{
char c;int x,v;
}q[4];

bool cmp(sb a,sb b){
if(a.x!=b.x) return a.x>b.x;
else return a.c<b.c;
}

int main() {
    ios::sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
      int a[128]={},hm=0;
      int m,n;cin>>n>>m;
      string s[51];
      vector<char> ans;
      for(int i=0;i<n;i++)  cin>>s[i];
      for(int i=0;i<m;i++){
        memset(q,0,sizeof q);

        for(int j=0;j<n;j++){
          if(s[j][i]=='A'){q[0].c=s[j][i];q[0].x++;q[0].v++;}
          if(s[j][i]=='T'){q[1].c=s[j][i];q[1].x++;q[1].v++;}
          if(s[j][i]=='G'){q[2].c=s[j][i];q[2].x++;q[2].v++;}
          if(s[j][i]=='C'){q[3].c=s[j][i];q[3].x++;q[3].v++;}
        }
        sort(q,q+4,cmp);
        ans.push_back(q[0].c);
        for(int i=1;i<4;i++) hm+=q[i].v;

      }
        for(auto i:ans) cout<<i;
        cout<<endl<<hm<<endl;
    }
    return 0;
}
