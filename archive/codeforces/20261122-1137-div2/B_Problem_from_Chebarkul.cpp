#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N, k;
    cin >> N >> k;

    vector<int> a(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i];   
    }   

    if(N == k){
        cout << N << "\n";
        return;
    }

    int cnt = N-k;
    
    int len = 0;
    int prv = -1;
    int ans = 0;
    for(int i = 1; i<=N; i++){
        if(prv != a[i]){
            len = 1;
        }
        else if(len<cnt)
        {
            len++;
        }
        else{
            ans++;
        }

        prv = a[i];
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