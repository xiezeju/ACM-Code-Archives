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

int n;


int main(){

    #ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>n,n){
        int ans = 0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                ans+=__gcd(i,j);
        cout<<ans<<endl;
    }

    return 0;
}
/*
#ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
    #endif

*/