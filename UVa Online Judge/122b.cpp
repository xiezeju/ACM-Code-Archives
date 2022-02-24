#include <bits/stdc++.h>

using namespace std;

const int N = 260;

struct Node{
    bool have_val;
    int v;
    Node *l,*r;
    Node():have_val(false),l(NULL),r(NULL){}
};
Node node[N];
Node* root;


vector<int> ans;
bool failed;

int cnt = -1;
Node* newnode(){
    Node *u = &node[++cnt];
    u->l = u->r = NULL;
    u->have_val = false;
    return u;
}

void addnode(int v,char* s){
    int n = strlen(s);
    Node* u = root;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            if(u->l==NULL) u->l = newnode();
            u = u->l;
        }
        else if(s[i]=='R'){
            if(u->r==NULL) u->r = newnode();
            u = u->r;
        }
        
    }
    if(u->have_val) failed = true;
    u->v = v;
    u->have_val = true;
}


bool bfs(vector<int>& ans){
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node* u = q.front(); q.pop();
        if(!u->have_val) return false;
        ans.push_back(u->v);
        if(u->l!=NULL) q.push(u->l);
        if(u->r!=NULL) q.push(u->r);
    }
    return true;
}

char s[N];
bool read_input(){
    failed = false;
    cnt = -1;
    root = newnode();
    for(;;){
        if(scanf("%s",s)!=1) return false;
        if(!strcmp(s,"()")) break;
        int v;
        sscanf(&s[1],"%d",&v);
        addnode(v,strchr(s,',')+1);
    }
    return true;
}


int32_t main(){

#ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
#endif

    while(read_input()){
        if (!bfs(ans)) failed = 1;
        if (failed)
            printf("not complete\n");
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                if (i != 0)printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }

    return 0;
}