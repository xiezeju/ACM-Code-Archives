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
const int maxn = 50;

char a[maxn][maxn];
int n,cnt=0;
bitset<30> r,ld,rd;                             //STL bitset初始化
void dfs(int y){
  if(y==n+1){++cnt;return;}                     //当前已经处理了n层递归说明找到了一个可行的解
  for(int x=1;x<=n;x++)
    if(a[x][y]!='*'&&!r[x] &&!ld[x-y+n] &&!rd[x+y]){
      r[x]=ld[x-y+n]=rd[x+y]=1;                 //对应的行和两个对角线标记为访问过
      dfs(y+1);                                 //去往下一层
      r[x]=ld[x-y+n]=rd[x+y]=0;                 //还原之前的标记状态，以便后续递归时再次访问
    }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);                                   //解除cin和cout的绑定，加快处理速度
  int x=1;
  while(cin>>n){
    if(!n) break;

    cnt=0;
    r.reset();ld.reset();rd.reset();            //初始化

    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        cin>>a[i][j];
    dfs(1);                                     //从第一列开始递归
    cout<<"Case "<<x++<<": "<<cnt<<endl;
  }
  return 0;
}
