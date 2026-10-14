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

    vector<int> pref(N+1, 0);
    for(int i = 1; i<=N; i++){
        pref[i] = (pref[i-1]+a[i])%K;
    }

    vector<ll> cnt(K, 0);
    ll ans = 0;

    for(int i = 1; i<=N; i++){
        if(i-K-1 >= 0){
            cnt[pref[i-K-1]]++;
        }

        ans += cnt[pref[i]];
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