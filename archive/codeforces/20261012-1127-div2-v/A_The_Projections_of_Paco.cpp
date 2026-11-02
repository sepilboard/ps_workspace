#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i<N; i++){
        cin >> a[i];
    }

    ll tot = 0;
    for(int i = 0; i<N; i++){
        tot = -tot + 2*a[i];
    }

    if(N&1){
        cout << tot/2 <<"\n";
    }
    else{
        cout << -tot/2 <<"\n";
    }
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}