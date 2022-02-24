#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 1000005;
int n, m;
int P[maxn];
int Sum[maxn];  //集合的和
int Tot[maxn];  //集合的个数
int id[maxn];   //id[i]代表结点i当前的位置
int pos;

void maketree()
{
    for (int i = 0; i < maxn; i++)
    {
        P[i] = i;
        Sum[i] = i;
        Tot[i] = 1;
        id[i] = i;
    }
    pos = n;
}

int Find(int x)
{
    if (x != P[x])
        return P[x] = Find(P[x]);
    return P[x];
}

//将y连接到x上
void unite(int x, int y)
{
    int p1 = Find(x);
    int p2 = Find(y);
    if (p1 != p2)
    {
        P[p2] = p1;
        Sum[p1] += Sum[p2];
        Tot[p1] += Tot[p2];
    }
}

//由于是根节点时不能直接移动,所以新开辟了一个id数组记录数字i最后的位置
//将数字i移动到集合S
void Move(int i, int S)
{
    int p1 = Find(id[i]);
    int p2 = Find(S);
    if (p1 != p2)
    {//原结点变成了虚拟根结点,对结果无影响
        Tot[p1]--;
        Tot[p2]++;
        Sum[p1] -= i;
        Sum[p2] += i;
        id[i] = ++pos;
        P[pos] = p2;    //给结点i新分配一个结点下标,放在原数组的后面
    }

}

int main()
{
    while (scanf("%d %d", &n, &m) != EOF)
    {
        maketree();
        for (int i = 0; i < m; i++)
        {
            int c1, p, q;
            scanf("%d %d", &c1, &p);
            if (c1 == 1)
            {
                scanf("%d", &q);
                unite(id[q], id[p]);
            }
            else if (c1 == 2)   //不能直接让p指向新的集合(有可能时根节点)
            {
                scanf("%d", &q);
                Move(p, id[q]);
            }
            else
            {
                int root = Find(id[p]);
                printf("%d %d\n", Tot[root], Sum[root]);
            }
        }
    }

    return 0;
}
