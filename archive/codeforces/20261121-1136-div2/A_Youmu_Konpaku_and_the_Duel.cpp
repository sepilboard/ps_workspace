#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int x;
    cin >> x;

    int ans = 1e+9;
    for(int i = 0; i<x; i++){
        int cur = 1+i;
        int cnt = 0;

        int cur_x = x;
        while(cur_x>0){
            cur_x -= cur;
            cnt++;
            cur--;
        }

        ans = min(ans, cnt+i);
    }   

    cout << ans << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}