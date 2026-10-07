#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

vector<char> is_p;
ll psum[200'005];

void solve()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> A(n);
    for(int i = 0; i<n; i++){
        cin >> A[i];
    }

    ll ans = 0;
    for(int a: A){
        int x = 1e+9;
        for(int i = 1; i*i<=a; i++){
            if(a%i) continue;
            if(i<=k) x = min(x, a/i);
            if(a/i<=k) x = min(x, i);
        }

        for(int i = 2; i<=200'000; i++){
            if(!is_p[i]) continue;
            int idx = 1;
            while(x%i){
                idx *= i;
                x /= i;
            }
            ans += psum[idx];
            cout << idx << "\n";
        }
    }

    cout << ans << "\n";
}

signed main()
{
    FASTIO;

    psum[1] = 0;
    is_p.resize(200'001, true);
    is_p[1] = false;
    for(ll i = 2; i<=200'000; i++){
        if(!is_p[i]) continue;
        psum[i] = 1;
        for(ll j = i*i; j<=200'000; j++){
            psum[j] = psum[j/i] + j/i;
        }
    }

    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}