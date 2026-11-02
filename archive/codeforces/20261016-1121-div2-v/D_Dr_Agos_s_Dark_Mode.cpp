#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<char> ans(N, '0');

    int n = N;
    if((N+1)%4 == 0) n = N-1;

    int n2;
    if(n&1){
        n2 = n/2;
    }
    else{
        n2 = (n-1)/2;
    }
    
    ans[n2] = '1';

}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}