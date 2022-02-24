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


int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
    if(!n&&!m) break;
    set<int> a;
    for(int i=1;i<=n+m;i++){
      int q;cin>>q;
      a.insert(q);
    }
    cout<<m+n-a.size()<<endl;
	}
	return 0;
}
