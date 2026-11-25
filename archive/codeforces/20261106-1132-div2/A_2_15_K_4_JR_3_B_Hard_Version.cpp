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
    sort(a.begin(), a.end(), greater<>());

    ll A = 0LL;
    ll B = 0LL;
    
    for(int i = 0; i<N; i++){
        if(A>B){
            swap(A, B);
        }

        A += (1LL<<a[i]);
    }

    cout << A*B << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}