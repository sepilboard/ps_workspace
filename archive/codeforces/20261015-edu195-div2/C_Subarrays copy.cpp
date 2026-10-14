#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N, K;
    cin >> N >> K;

    vector<int> a(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i];   
    }

    vector<ll> dp(N+1, 0LL);
    vector<vector<int>> stk(K, vector<int>());
    stk[0].push_back(0);
    if(a[1]%K == 0) dp[0] =1;
    ll cur_r = 0LL;
    ll ans = 0LL;
    for(int i = 1; i<=N; i++){
        cur_r = (cur_r+a[i])%K;

        // if(cur_r == 0){
        //     stk[(K-(a[i]%K))%K].push_back(i);
        // }

        if(!stk[(K-(cur_r%K))%K].empty()){
            int idx = stk[(K-(cur_r%K))%K].back();
            stk[(K-(cur_r%K))%K].pop_back();

            if(idx == 0) dp[i] = 1;
            else dp[i] = dp[idx-1]+1;
            cout << i <<":" << cur_r << ": "<<idx<<"," << dp[i] <<"\n";
            ans += dp[i];
        }
        // else if((K-(cur_r%K))%K == 0){
        //     dp[i] = 1;
        //     cout << i <<": "<<dp[i] <<"\n";
        //     ans += dp[i];
        // }

        stk[(K-(a[i]%K))%K].push_back(i);
        if(cur_r != 0){
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