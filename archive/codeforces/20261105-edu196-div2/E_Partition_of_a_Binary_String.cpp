#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;
#define MOD 998244353

void solve()
{
    int N;
    cin >> N;
    
    vector<char> a(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i];   
    }

    vector<vector<ll>> dp(N+1, vector<ll>(2*N+1, -1));
    dp[0][0] = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<=2*N; j++){
            if(dp[i-1][0] == -1) continue;

            if(dp[i][j+1] == -1) dp[i][j+1] = 0;
            dp[i][j+1] = (dp[i][j+1] + dp[i-1][j])%MOD;
            if(i+2<=N && a[i] != a[i+1] && a[i+1] != a[i+2]){
                if(dp[i+2][j+6] == -1) dp[i+2][j+6] = 0;
                dp[i+2][j+6] = (dp[i+2][j+6] + dp[i-1][j])%MOD;
            }
        }
    }

    for(int j = 2*N; j>=0; j--){
        if(dp[N][j] == -1) continue;
        
        cout << dp[N][j] << "\n";
    }
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}