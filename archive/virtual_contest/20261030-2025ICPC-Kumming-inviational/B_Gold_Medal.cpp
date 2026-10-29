#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N, k;
    cin >> N >> k;
    
    vector<int> a(N);
    vector<int> res(N);
    ll ans = 0;
    for(int i = 0; i<N; i++){
        cin >> a[i];
        res[i] = (k - (a[i]%k));
        ans += a[i]/k;
    }

    int m;
    cin >> m;
    
    sort(res.begin(), res.end());
    for(int i = 0; i<N; i++){
        if(res[i]>m){
            break;
        }

        m -= res[i];
        ans++;
    }

    ans += m/k;
    
    cout << ans << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}