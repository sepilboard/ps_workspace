#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<int> a(2*N+1);
    vector<int> prv(N+1);
    vector<int> to(2*N+1);

    for(int i = 1; i<=2*N; i++){
        cin >> a[i];
        
        if(prv[a[i]] == 0){
            prv[a[i]] = i;
        }
        else{
            to[prv[a[i]]] = i;
            to[i] = i;
        }
    }

    vector<ll> dp(2*N+2, 0);

    for(int i = 1; i<=2*N; i++){
        dp[i+1] = max(dp[i+1], dp[i]+1);
        dp[to[i]+1] = max(dp[to[i]+1], dp[i]+1LL*(to[i]-i+1)*(to[i]-i+1));
    }
    // cout << dp[1] <<"\n";

    cout << dp[2*N+1] <<"\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}

// https://codeforces.com/contest/2248/problem/C