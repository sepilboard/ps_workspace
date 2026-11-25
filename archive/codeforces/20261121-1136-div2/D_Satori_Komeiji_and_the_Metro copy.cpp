#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<ll> a(N);
    for(int i = 0; i<N; i++){
        cin >> a[i];
    }   

    if(N == 2){
        cout << a[0]+a[1] << "\n";
        return;
    }

    sort(a.begin(), a.end());
    ll ans = 0LL;
    for(int i = 0; i<N-2; i++){
        ans += a[i];
    }
    ans += a[N-1];

    cout << ans << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}