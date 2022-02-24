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
const int N = 1010;

int r,c;
int xj,yj;

char a[N][N];
int  fire[N][N];
bool v[N][N];

int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};

struct node{
    int x,y;
    int t;
};

queue<node> f;
void bfs_fire(int xf,int yf)
{
    queue<node> q;
    q.push({xf,yf,0});
    fire[xf][yf] = 0;
    while(!q.empty()){
        node u = q.front();q.pop();
        for(int i=0;i<4;i++){
            int x = u.x+dr[i];
            int y = u.y+dc[i];
            int t = u.t;
            if(x<1||x>r||y<1||y>c) continue;
            if(fire[x][y]>t+1&&a[x][y]!='#'){
                fire[x][y] = t+1;
                q.push({x,y,t+1});
            }
        }
    }
}

int ans;
void bfs_j(){
    queue<node> q;
    q.push({xj,yj,0});
    v[xj][yj] = 1;
    while(!q.empty()){
        node u = q.front();q.pop();
        for(int i=0;i<4;i++){
            int x = u.x+dr[i];
            int y = u.y+dc[i];
            int t = u.t;
            if(x<1||x>r||y<1||y>c){
                ans = min(ans,t+1);
                continue;
            }
            if(v[x][y]||a[x][y]=='#') continue;
            if(t+1<fire[x][y]&&a[x][y]=='.'){
                v[x][y] = 1;
                q.push({x,y,t+1});
            }
            
                
        }
    }
}

int main(){

    #ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>r>>c;
        memset(fire,0x3f,sizeof(fire));
        memset(v,0,sizeof(v));
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++){
                char b;cin>>b;
                a[i][j] = b;
                if(b=='J')
                    xj=i,yj=j;
                else if(b=='F')
                    f.push({i,j,0});
                    
            }
        while(!f.empty()){
            node u = f.front();f.pop();
            bfs_fire(u.x,u.y);
        }
        /*for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++)
                cout<<fire[i][j]<<" ";
            cout<<endl;
        }    */  
        ans = 1e9;
        bfs_j();
        if(ans==1e9)
            cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;
        
    }

    return 0;
}