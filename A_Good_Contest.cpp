#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;   
    int a1, a2, a3;
    cin >> n;
    cin >> a1 >> a2 >> a3;

    cout << max(max(n-a1, n-a2), n-a3) <<"\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}