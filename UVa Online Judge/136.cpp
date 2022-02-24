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

const int a[3]={2,3,5};


int32_t main(){

    #ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    set<ll> s;
    pq.push(1);
    s.insert(1);
    for(int i=1;;i++){
        ll x = pq.top();pq.pop();
        if(i==1500){
            cout << "The 1500'th ugly number is "<<x<<".\n";
            break;
        }
        for(int j=0;j<3;j++){
            ll x2 = x*a[j];
            if(!s.count(x2)){
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
    return 0;
}