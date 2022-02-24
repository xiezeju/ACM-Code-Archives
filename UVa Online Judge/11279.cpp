#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const int LLINF = 4e18;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(false);
  int n,x=1;
  while(cin>>n){
    if(n==0)break;
    int a[n],c1=0,c2=0;
    for(int i = 0;i<n;i++){
      cin>>a[i];
      if(a[i]==0)c2++;
      else c1++;
    }
    cout<<"Case "<<x++<<": "<<c1-c2<<endl;

  }
  return 0;
}
