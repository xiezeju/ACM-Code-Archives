#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 2e6 + 10;


int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    int x = 1;
    while (t--) {
        int n[3];
        for(int i=0;i<3;i++) cin>>n[i];
        set<int> s[3],g;
        for(int i=0;i<3;i++)
        for(int j=n[i]-1;j>=0;j--){
          int q;cin>>q;
          s[i].insert(q);
          g.insert(q);
        }
        cout << "Case #" << x++ << ":" << endl;
        for (int i = 0; i < 3; i++) {
          int p=0,q=0;
          for(auto &x:s[i]){
            int flag=1;
            for(int j=0;j<3;j++){
              if(i==j) continue;
              if(s[j].count(x)) {flag=0;break;}
            }
            if(flag) p++;
          }
          for(auto &x:g){
              if(s[i].count(x)) continue;
              int flag=1;
            for(int j=0;j<3;j++){
              if(i==j) continue;
              if(!s[j].count(x)) {flag=0;break;}
            }
            if(flag) q++;
          }
          cout<<p<<" "<<q<<endl;
        }



    }
    return 0;
}
