#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 30010;

int a[maxn];

class UnionFind {
private:
    vi p, r, s;
public:
   UnionFind(int n){
    p.assign(n+1,0); for(int i=0;i<=n;i++) p[i]=i; //初始化
    r.assign(n+1,0);                               //启发式合并，可选的加速项，用于存储子树高度
    s.assign(n+1,1);                               //用于存储子树的元素个数
   }

   int find(int i){return p[i]==i?i:p[i]=find(p[i]);} //查找
   bool same(int i,int j){return find(i)==find(j);}    //判断i和j是否在同一颗树上
   int size(int i){return s[find(i)];}             //查询子树的元素个数

   void us(int i, int j){
    if(same(i,j)) return;                          //确保i和j不在同一颗子树上才能合并
    int x=find(i),y=find(j);
    if(r[x]>r[y]) swap(x,y);                       //启发式合并，可选，确保树的高度是不增的，加速查找效率
    if(r[x]==r[y]) r[y]++;                         //启发式合并，可选，随便选一棵树加到另一颗树上，树的高度+1
    p[x]=y;                                        //把x子树加到子树y的根节点上
    s[y]+=s[x];                                    //更新合并后树的元素的个数
   }
};



int main() {
    ios::sync_with_stdio(false);
    int n,m;
    while (cin>>n>>m) {
        if(!n&&!m) break;
        UnionFind s(n);
        string a,c;
        map<string,int>mp;
        for(int i=0;i<n;i++){
          cin>>a;
          mp[a]=i;
        }
        for(int i=0;i<m;i++){
          cin>>a>>c;
          s.us(mp[a],mp[c]);
        }
        int Max=-1;
        for(int i=0;i<n;i++) if(s.size(i)>Max) Max=s.size(i);
        cout<<Max<<endl;


    }
    return 0;
}
