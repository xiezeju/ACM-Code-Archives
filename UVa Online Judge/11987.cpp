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
int Sum[maxn];  //���ϵĺ�
int Tot[maxn];  //���ϵĸ���
int id[maxn];   //id[i]������i��ǰ��λ��
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

//��y���ӵ�x��
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

//�����Ǹ��ڵ�ʱ����ֱ���ƶ�,�����¿�����һ��id�����¼����i����λ��
//������i�ƶ�������S
void Move(int i, int S)
{
    int p1 = Find(id[i]);
    int p2 = Find(S);
    if (p1 != p2)
    {//ԭ���������������,�Խ����Ӱ��
        Tot[p1]--;
        Tot[p2]++;
        Sum[p1] -= i;
        Sum[p2] += i;
        id[i] = ++pos;
        P[pos] = p2;    //�����i�·���һ������±�,����ԭ����ĺ���
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
            else if (c1 == 2)   //����ֱ����pָ���µļ���(�п���ʱ���ڵ�)
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
