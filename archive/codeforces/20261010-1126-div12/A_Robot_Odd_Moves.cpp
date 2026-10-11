#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int a, b;
    cin >> a >> b;
    if(b-a>1) cout << -1 <<"\n";
    else if((a-b)%2 == 0) cout << a <<"\n";
    else cout << a+1 <<"\n";   
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}