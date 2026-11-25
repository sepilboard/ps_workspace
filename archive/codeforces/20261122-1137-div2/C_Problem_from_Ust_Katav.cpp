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
    a[0] = -1;

    ll ans = 0LL;
    ll len = 0LL;
    for(int i = 1; i<=N; i++){
        if(a[i-1] < a[i]){
            len++;
        }
        else{
            len = 1;
        }
        ans += len;
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