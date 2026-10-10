#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int c, h, o;
    cin >> c >> h >> o;
    if(h<2*c-4){
        cout << "Unsaturated\n";
    }   
    else{
        cout << "Saturated\n";
    }
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}