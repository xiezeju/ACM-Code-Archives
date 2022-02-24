#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define LSOne(S) ((S) & -(S))
#define INF 0x3f3f3f3f
//#define int long long

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const long long LLINF = 4e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int N = 10010;


int a[N];

int32_t main(){

    #ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    int x = 1;
    while(cin>>n>>q,n&&q){
        printf("CASE# %d:\n",x++);
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        while(q--){
            int op;cin>>op;
            int ans = lower_bound(a,a+n,op)-a;
            if(a[ans]==op)
                printf("%d found at %d\n",op,ans+1);
            else printf("%d not found\n",op);
        }
    }

    return 0;
}