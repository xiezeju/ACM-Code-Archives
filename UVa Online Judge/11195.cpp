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
bitset<30> r,ld,rd;                             //STL bitset��ʼ��
void dfs(int y){
  if(y==n+1){++cnt;return;}                     //��ǰ�Ѿ�������n��ݹ�˵���ҵ���һ�����еĽ�
  for(int x=1;x<=n;x++)
    if(a[x][y]!='*'&&!r[x] &&!ld[x-y+n] &&!rd[x+y]){
      r[x]=ld[x-y+n]=rd[x+y]=1;                 //��Ӧ���к������Խ��߱��Ϊ���ʹ�
      dfs(y+1);                                 //ȥ����һ��
      r[x]=ld[x-y+n]=rd[x+y]=0;                 //��ԭ֮ǰ�ı��״̬���Ա�����ݹ�ʱ�ٴη���
    }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);                                   //���cin��cout�İ󶨣��ӿ촦���ٶ�
  int x=1;
  while(cin>>n){
    if(!n) break;

    cnt=0;
    r.reset();ld.reset();rd.reset();            //��ʼ��

    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        cin>>a[i][j];
    dfs(1);                                     //�ӵ�һ�п�ʼ�ݹ�
    cout<<"Case "<<x++<<": "<<cnt<<endl;
  }
  return 0;
}
