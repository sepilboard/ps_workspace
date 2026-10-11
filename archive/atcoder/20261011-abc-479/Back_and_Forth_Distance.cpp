#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    int N, Q;
    cin >> N >> Q;

    vector<int> L(N+1);
    vector<int> R(N+1);
    for(int i = 2; i<=N; i++){
        cin >> L[i];
    }
    for(int i = 1; i<=N-1; i++){
        cin >> R[i];
    }

    vector<int> pref_mnR(N+1, 1e+9+1);
    for(int i = 1; i<=N; i++){
        pref_mnR[i] = min(pref_mnR[i-1], R[i]);
    }
    vector<int> suf_mnL(N+2, 1e+9+1);
    for(int i = N; i>=1; i--){
        suf_mnL[i] = min(suf_mnL[i+1], L[i]);
    }

    for(int q = 0; q<Q; q++){
        int s, t;
        cin >> s >> t;

        if(s<t){
            int ans = min(R[s], L[s]+pref_mnR[s-1]);
            cout << ans << "\n";
        }
        else{
            int ans = min(L[s], R[s]+suf_mnL[s+1]);
            cout << ans << "\n";
        }
    }

    
    return 0;
}