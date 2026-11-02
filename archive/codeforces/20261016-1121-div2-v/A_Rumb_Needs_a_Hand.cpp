#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;   
    vector<int> r;
    for(int i = 1; i<=N; i++){
        int p;
        cin >> p;
        if(p != i){
            r.push_back(p);
        }
    }

    int n = (int)r.size();
    for(int i = 1; i<n; i++){
        if(r[i-1]<r[i]){
            cout << "NO\n";
            return;
        }
    }   
    
    cout << "YES\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}