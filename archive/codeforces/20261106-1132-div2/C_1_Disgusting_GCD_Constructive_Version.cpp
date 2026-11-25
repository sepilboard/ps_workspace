#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

vector<int> prime;
vector<char> is_p;

void solve()
{
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i<N; i++){
        cin >> a[i];   
    }

    for(int i = 0; i<N; i++){
        cout << *lower_bound(prime.begin(), prime.end(), a[i]) <<" ";
    }
    cout << "\n";
}

signed main()
{
    FASTIO;

    is_p.assign(200'001, true);
    is_p[1] = false;
    for(int i = 2; i<=200'000; i++){
        if(!is_p[i]) continue;
        prime.push_back(i);
        for(ll j = 1LL*i*i; j<=200'000; j+=i){
            is_p[j] = false;
        }
    }

    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}