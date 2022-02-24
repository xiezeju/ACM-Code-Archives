#include<bits/stdc++.h>
using namespace std;

int32_t main()
{

#ifdef Online_Judge
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    
    while (t--)
    {
        
        int D, I;cin >> D >> I;
        int k=1;
        for(int i=0;i<D-1;i++){
            if(I%2){k = 2*k; I = (I+1)/2;}
            else {k=2*k+1;I /=2;}
        }
        cout<<k<<endl;
    }

    return 0;
}