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
const int N = 100010;
int p[N+1];
bool is_tree;
void init()
{
    for (int i = 0; i <= N; i++)
        p[i] = i;
}

int find(int x)
{
    return p[x] == x ? x : find(p[x]);
}

void add(int i, int j)
{
    int x = find(i);
    int y = find(j);
    if (x == y){
        is_tree = false;
        return;
    }
    p[y] = x;
}

int main(){

    #ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    int k=1;
    while(cin>>a>>b){
        if(a<0&&b<0)break;
        if(a==0&b==0){
            printf("Case %d is a tree.\n", k++);
            continue;
        }
        set<int> cnt;
        init();
        is_tree = true;
        add(a,b);
        cnt.insert(a);
        cnt.insert(b);
        while(cin>>a>>b,a||b){
            add(a,b);
            cnt.insert(a);
            cnt.insert(b);
        }
        int forest=0;
        for(auto i:cnt)
            if(i==find(i)) forest++;
        if(is_tree&&forest==1)
            printf("Case %d is a tree.\n",k);
        else
            printf("Case %d is not a tree.\n", k);
        k++;
    }
    return 0;
}