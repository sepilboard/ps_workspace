#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    
    ll lo = 0, hi = N+1;
    while(lo+1<hi){
        ll k = lo+hi>>1;
        
        ll cur = 0LL;
        for(int i = 1; i<=k; i++){
            cur += 1LL*i*(k/i);
            if(cur>=N){
                break;
            }
        }

        if(cur>=N){
            hi = k;
        }
        else{
            lo = k;
        }
    }

    cout << hi <<"\n";
    
    int tot = 0;
    int bag = 1;
    for(int org = hi; org>=1; org--){
        if(tot+ org*(hi/org) > N){
            break;
        }
        for(int cnt = 0; cnt<hi/org; cnt++){
            for(int i = 0; i<org; i++){
                cout << bag <<" ";
            }
            bag++;
        }
        tot += org*(hi/org);
    }
    
    for(int i = 0; i<N-tot; i++){
        cout << bag++ <<" ";
    }
    cout << "\n";
    
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}