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

    sort(a.begin(), a.end());

    ll cost = 0LL;
    ll freq = a[N-1]-a[0];
    for(int i = 0; i<N; i++){
        cost += abs(a[N/2] - a[i]);
    }

    cout << cost <<" " << freq <<"\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}