#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    
    int N, M, K;
    ll pa, pb;
    cin >> N >> M >> K >> pa >> pb;

    vector<ll> a(M+1);
    vector<ll> b(M+1);
    for(int i = 1; i<=M; i++){
        cin >> a[i];   
    }
    for(int i = 1; i<=M; i++){
        cin >> b[i];   
    }

    vector<array<ll, 4>> stxc(K);
    for(int i = 0; i<K; i++){
        ll s, t, x, c;
        cin >> s >> t >> x >> c;
        stxc[i] = {s, t, x, c};
    }

    ll lo = -1, hi = N+1;
    while(lo+1<hi){
        ll T = (lo+hi)/2;

        vector<array<ll, 3>> cnt(M+1, {0,0,0});
        for(int i = 0; i<K; i++){
            auto[s, t, x, c] = stxc[i];
            ll at = (pa-s+N)%N;
            ll bt = (pb-s+N)%N;

            if(at<=T && bt<=T) cnt[t][2]+=x;
            else if(at<=T && bt>T) cnt[t][0]+=x;
            else if(at>T && bt<=T) cnt[t][1]+=x;
        }

        bool flag = true;
        for(int i = 1; i<=M; i++){
            if(a[i]>cnt[i][0]+cnt[i][2]) flag = false;
            if(b[i]>cnt[i][1]+cnt[i][2]) flag = false;
            if(a[i]+b[i]>cnt[i][0]+cnt[i][1]+cnt[i][2]) flag = false;
            if(!flag) break;
        }

        if(flag) hi = T;
        else lo = T;
    }

    ll T = hi;

    if(T == N+1){
        cout << "impossible\n";
        return 0;
    }

    sort(stxc.begin(), stxc.end(), [](auto &fs, auto &sc){
        return fs[3]<sc[3];
    });

    vector<ll> tot(M+1);
    for(int i = 1; i<=M; i++){
        tot[i] = a[i] + b[i];
    }

    ll ans = 0LL;
    for(int i = 0; i<K; i++){
        auto[s, t, x, c] = stxc[i];
        
        ll at = (pa-s+N)%N;
        ll bt = (pb-s+N)%N;

        ll use = 0;
        if(at<=T && bt<=T){
            use = min(tot[t], x);
        }
        else if(at<=T && bt>T){
            use = min(tot[t], min(x, a[t]));
            a[t] -= use;
        }
        else if(at>T && bt<=T){
            use = min(tot[t], min(x, b[t]));
            b[t] -= use;
        }

        tot[t] -= use;
        ans += 1LL*c*use;
    }

    cout << T << " " << ans << "\n";
    
    return 0;
}