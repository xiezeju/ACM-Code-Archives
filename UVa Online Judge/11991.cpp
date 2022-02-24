#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int N = 1e6+10;
map<int, vi> a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m){
        
        a.clear();

        for(int i=1;i<=n;i++){
            int v;cin>>v;
            a[v].push_back(i);
        }
        
        while(m--){
            int k,v;cin>>k>>v;
            if(a[v].size()>=k)
            cout<<a[v][k-1]<<endl;
            else cout<<0<<endl;
        }        
    }

    return 0;
}