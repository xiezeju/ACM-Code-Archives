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
	int t;cin>>t;
	while(t--){
    int n,m;cin>>n>>m;
    int q,ans=0;
    multiset<int> a,b;
    for(int i=0;i<n;i++) {cin>>q;a.insert(q);}
    for(int i=0;i<m;i++) {cin>>q;b.insert(q);}
    auto it=b.begin();
    int pre;
    for(;it!=b.end();it++){
      if(it==b.begin()) pre=*it;
      else if(*it==pre) continue;
      if(a.count(*it)){
        ans+=abs((int)(a.count(*it)-b.count(*it)));
        a.erase(*it);
      }else ans+=b.count(*it);
      pre = *it;
    }
    ans+=a.size();
    cout<<ans<<endl;
	}
	return 0;
}
