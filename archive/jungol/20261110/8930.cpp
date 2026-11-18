#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    
    int N, Q;
    cin >> N >> Q;

    vector<ll> a(N);
    for(int i = 0; i<N; i++){
        cin >> a[i];   
    }

    for(int i = 1; i<N; i++){
        a[i] = min(a[i], 2*a[i-1]);
    }

    while(a.size() < 32){
        a.push_back(a.back()*2);
    }

    for(int q = 0; q<Q; q++){
        int x;
        cin >> x;

        ll ans = 0;
        for(int i = 0; i<31; i++){
            if(x&(1<<i)){
                ans += a[i];
            }

            ans = min(ans, a[i+1]);
        }
        
        cout << ans << "\n";
    }

    return 0;
}