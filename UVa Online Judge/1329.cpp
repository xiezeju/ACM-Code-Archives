#include<bits/stdc++.h>

using namespace std;
const int maxn = 20000 + 5;
int par[maxn];
int d[maxn];
int T,n;
char c;
int u, v;

void init() {
    for(int i = 0; i < maxn; i++){
        par[i] = i;
        d[i] = 0;
    }
}

int find(int x){
    if(par[x] == x)return x;
    int f = find(par[x]);
    d[x] += d[par[x] ];
    return par[x] = f;
}

int main(){
    ios :: sync_with_stdio(false);
    cin >> T;
    while(T--) {
        init();
        cin >> n;
        while(cin >> c) {
            if(c == 'O') break;
            else if(c == 'I') {
                cin >> u >> v;
                par[u] = v;
                d[u] = abs(u - v) % 1000;
            }
            else if(c == 'E') {
                cin >> u;
                find(u);
                cout << d[u] << endl;
            }
        }
    }
    return 0;
}
