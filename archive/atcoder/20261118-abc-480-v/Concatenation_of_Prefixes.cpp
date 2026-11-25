#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    
    int N, Q;
    cin >> N >> Q;

    vector<ll> a(N+1);
    vector<ll> psum(N+1);
    vector<ll> ppsum(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
        ppsum[i] = ppsum[i-1] + psum[i];
    }

    vector<ll> len(N+1);
    for(int i = 1; i<=N; i++){
        len[i] = len[i-1]+i;
    }

    for(int q = 0; q<Q; q++){
        ll ans = 0LL;
        ll L, R;
        cin >> L >> R;

        int sidx = lower_bound(len.begin(), len.end(), L) - len.begin();
        int eidx = lower_bound(len.begin(), len.end(), R) - len.begin();

        ans += ppsum[eidx]-ppsum[sidx];

        ans -= psum[eidx] - psum[eidx - (len[eidx]-R)];
        ans += psum[sidx] - psum[sidx - (len[sidx]-L) -1];

        cout << ans << "\n";
    }

    
    return 0;
}