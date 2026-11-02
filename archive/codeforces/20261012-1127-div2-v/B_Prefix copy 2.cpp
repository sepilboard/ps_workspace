#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    
    vector<int> a(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i];        
    }

    int base = 2'500;
    vector<vector<char>> dp(N+1, vector<char>(5'001));
    dp[0][base] = true;

    int ans = -1e+9;
    for(int i = 1; i<=N; i++){
        dp[i][a[i]+base] = true;
        for(int prv = 0; prv<=5'000; prv++){
            if(!dp[i-1][prv]) continue;
            
            int rprv = prv-base;
            int cur1 = a[i]+rprv + base;
            int cur2 = a[i]-rprv + base;
            if(0<=cur1 && cur1<=5'000) dp[i][cur1] = true, ans = max(ans, cur1-base);
            if(0<=cur2 && cur2<=5'000) dp[i][cur2] = true, ans = max(ans, cur2-base);
        }
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