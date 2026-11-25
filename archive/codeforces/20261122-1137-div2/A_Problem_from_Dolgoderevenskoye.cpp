#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    ll N;
    cin >> N;

    if(N%2 == 1){
        cout << "Yes\n";
        return;
    }

    if((N/2)%2 == 1){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
    }
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}