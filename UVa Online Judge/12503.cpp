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
    while(t--){
      int q;cin>>q;
      string s[q+1];
      int x = 0;
      for(int i = 1;i<=q;i++){
        string c;cin>>c;
        if(c=="LEFT") {s[i]=c;x--;}
        else if(c=="RIGHT") {s[i]=c;x++;}
        else {
          int op;
          cin>>c>>op;
          if(s[op]=="LEFT") {s[i]=s[op];x--;}
          if(s[op]=="RIGHT") {s[i]=s[op];x++;}
        }
      }
      cout<<x<<endl;
    }
    return 0;
}


