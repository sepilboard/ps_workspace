#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N, M;
    cin >> N >> M;
    
    vector<ll> a(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i];
    }

    ll sum = 0LL;
    priority_queue<ll> pq;
    for(int i = 1; i<M; i++){
        sum += a[i];
        pq.push(a[i]);
    }

    ll ans = -1e+18;
    for(int i = M; i<=N; i++){
        ans = max(ans, a[i]*M - sum);

        if(!pq.empty()){
            ll mx = pq.top();
            if(mx>a[i]){
                pq.pop();
                pq.push(a[i]);
                sum = sum-mx+a[i];
            }
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