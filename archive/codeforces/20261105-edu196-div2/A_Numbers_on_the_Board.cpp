#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int l, r;
    cin >> l >> r;

    if(l*r > 0){
        cout << r-l <<"\n";
        return;
    }   

    cout << max(0, abs(r+l)-1) << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}