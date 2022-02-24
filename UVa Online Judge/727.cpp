#include <bits/stdc++.h>
//TLE 版本

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int maxn = 2e6 + 10;



int main() {
    int t; cin >> t;
    while (t--) {
        stack<char> a;
        string s, c;
        while (cin >> c) s = s + c;
        for (int i = 0; i < s.size(); i++) {
            if (a.empty()) {a.push(s[i]); continue;}
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (s[i] == '+') {
                    if (a.top() != '(') a.push(s[i]);
                    else {
                        while (!a.empty() && a.top() != '(') {
                            cout << a.top();
                            a.pop();
                        }
                        a.push(s[i]);
                    }
                }
                if (s[i] == '-') {
                    if (a.top() == '(') a.push(s[i]);
                    else {
                        while (!a.empty() && a.top() != '(') {
                            cout << a.top();
                            a.pop();
                        }
                        a.push(s[i]);
                    }
                }
                if (s[i] == '*') {
                    if (a.top() == '(' || a.top() == '+' || a.top() == '-') a.push(s[i]);
                    else {
                        while (!a.empty() && a.top() != '(' && a.top() != '+' && a.top() != '-') {
                            cout << a.top();
                            a.pop();
                        }
                        a.push(s[i]);
                    }
                }
                if (s[i] == '/') {
                    if (a.top() == '(' || a.top() == '+' || a.top() == '-') a.push(s[i]);
                    else {
                        while (!a.empty() && a.top() != '(' && a.top() != '+' && a.top() != '-') {
                            cout << a.top();
                            a.pop();
                        }
                        a.push(s[i]);
                    }
                }
            } else if (s[i] == '(')a.push(s[i]);
            else if (s[i] == ')') {
                while (!a.empty() && a.top() != '(') {
                    cout << a.top();
                    a.pop();
                } if (a.top() == '(') a.pop();
            } else cout << s[i];
        }
        while (!a.empty()) {cout << a.top(); a.pop();}
        cout << endl;
    }
    return 0;
}
//AC版本


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <stack>

using namespace std;

char str[ 51 ];
int  mat[ 51 ];

//segment_tree__begin
typedef struct tnode
{
	tnode* Lchild;
	tnode* Rchild;
	int	   Lvalue;
	int    Rvalue;
	int    Min;
	int	   Spa;
}tnode;
tnode Node[ 105 ];

tnode* Root;
int    Count;
tnode* madetree( int a, int b ) {
	tnode* np  = &Node[ Count ++ ];
	np->Lvalue = a;
	np->Rvalue = b;
	np->Min = 100000;
	if ( a < b ) {
		np->Lchild = madetree( a, (a+b)/2 );
		np->Rchild = madetree( (a+b)/2+1, b );
	}else {
		np->Lchild = NULL;
		np->Rchild = NULL;
	}
	return np;
}
void segment_tree( int a, int b ) {
	Count = 0;
	Root = madetree( a, b );
}
void Insert( tnode* r, int p, int v ) {
	if ( r->Lvalue == p && r->Rvalue == p ) {
		r->Min = v;
		r->Spa = p;
		return;
	}
	int mid = (r->Lvalue+r->Rvalue)/2;
	if ( p <= mid ) {
		Insert( r->Lchild, p, v );
		if ( r->Min == r->Lchild->Min && r->Spa < r->Lchild->Spa )
			r->Spa = r->Lchild->Spa;
		else if ( r->Min > r->Lchild->Min ) {
			r->Min = r->Lchild->Min;
			r->Spa = r->Lchild->Spa;
		}
	}else {
		Insert( r->Rchild, p, v );
		if ( r->Min == r->Rchild->Min && r->Spa < r->Rchild->Spa )
			r->Spa = r->Rchild->Spa;
		else if ( r->Min > r->Rchild->Min ) {
			r->Min = r->Rchild->Min;
			r->Spa = r->Rchild->Spa;
		}
	}
}
tnode Query( tnode* r, int a, int b ) {
	if ( r->Lvalue == a && r->Rvalue == b )
		return *r;
	int mid = (r->Lvalue+r->Rvalue)/2;
	if ( b <= mid )
		return Query( r->Lchild, a, b );
	else if ( a > mid )
		return Query( r->Rchild, a, b );
	else {
		tnode A = Query( r->Lchild, a, mid );
		tnode B = Query( r->Rchild, mid+1, b );
		if ( A.Min >= B.Min )
			return B;
		else return A;
	}
}
void Insert( int p, int v ) {
	Insert( Root, p, v );
}
tnode Query( int a, int b ) {
	return Query( Root, a, b );
}
//segment_tree__end

int level( char c )
{
	switch( c ) {
		case '(':
		case ')': return 10000;
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 5;
	}
	return 10000;
}

void f( char* s, int l, int r )
{
	if ( l == r ) {
		printf("%c",s[l]);
		return;
	}
	//去括号
	if ( str[l] == '(' && mat[l] == r ) {
		f( s, l+1, r-1 );
		return;
	}
	//寻找最低优先级
	int spa = Query( l, r ).Spa;
	f( s, l ,spa-1 );
	f( s, spa+1, r );
	printf("%c",s[spa]);
}

int main()
{
	int n;
	while ( cin >> n ) {
		getchar();
		getchar();
		while ( n -- ) {
			int count = 0;
			while ( gets(&str[count]) ) {
				if( !str[count] )
					break;
				++ count;
			}
			str[count] = 0;

			stack<int>S;
			for ( int i = 0 ; i < count ; ++ i ) {
				if ( str[i] == '(' )
					S.push(i);
				if ( str[i] == ')' ) {
					mat[S.top()] = i;
					S.pop();
				}
			}

			segment_tree( 0, count-1 );
			int add = 0;
			for ( int i = 0 ; i < count ; ++ i ) {
				if ( str[i] == '(' ) add += 100;
				if ( str[i] == ')' ) add -= 100;
				Insert( i, add+level(str[i]) );
			}
			f( str, 0, count-1 );
			printf("\n");
			if ( n ) printf("\n");
		}
	}
	return 0;
}
