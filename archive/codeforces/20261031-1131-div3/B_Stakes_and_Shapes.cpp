#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int r, s, p;
    cin >> r >> s >> p;   
    
    int N = r+s+p;
    if(r>s){
        for(int i = 0; i<N; i++){
            cout << 'P';   
        }
    }
    else if(p>s){
        for(int i = 0; i<N; i++){
            cout << 'S';   
        }
    }
    else{
        for(int i = 0; i<N; i++){
            cout << 'R';   
        }
    }

    cout << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}