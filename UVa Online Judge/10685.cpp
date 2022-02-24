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
    p.assign(n+1,0); for(int i=0;i<=n;i++) p[i]=i; //��ʼ��
    r.assign(n+1,0);                               //����ʽ�ϲ�����ѡ�ļ�������ڴ洢�����߶�
    s.assign(n+1,1);                               //���ڴ洢������Ԫ�ظ���
   }

   int find(int i){return p[i]==i?i:p[i]=find(p[i]);} //����
   bool same(int i,int j){return find(i)==find(j);}    //�ж�i��j�Ƿ���ͬһ������
   int size(int i){return s[find(i)];}             //��ѯ������Ԫ�ظ���

   void us(int i, int j){
    if(same(i,j)) return;                          //ȷ��i��j����ͬһ�������ϲ��ܺϲ�
    int x=find(i),y=find(j);
    if(r[x]>r[y]) swap(x,y);                       //����ʽ�ϲ�����ѡ��ȷ�����ĸ߶��ǲ����ģ����ٲ���Ч��
    if(r[x]==r[y]) r[y]++;                         //����ʽ�ϲ�����ѡ�����ѡһ�����ӵ���һ�����ϣ����ĸ߶�+1
    p[x]=y;                                        //��x�����ӵ�����y�ĸ��ڵ���
    s[y]+=s[x];                                    //���ºϲ�������Ԫ�صĸ���
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
