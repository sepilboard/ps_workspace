#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int a, b;
    cin >> a >> b;

    if(a<=b){
        cout << "-1\n";
        return;
    }

    int cnt = 0;
    while(a>b && b>0){
        a-=2;
        b-=1;
        cnt++;
    }
    cout << cnt <<"\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}