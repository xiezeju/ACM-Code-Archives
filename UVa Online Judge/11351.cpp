#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
const int INF = 0x3f3f3f3f;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 1010;

int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    int x=1;
    while(t--){
      int n,k;cin>>n>>k;
      int j=0;
      for(int i=2;i<=n;i++){
        j = (j+k)%i;
      }
      cout<<"Case "<<x++<<": "<<j+1<<endl;
    }

    return 0;
}
