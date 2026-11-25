#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N, k;
    cin >> N >> k;
    
    vector<int> a(N);
    for(int i = 0; i<N; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    if(a[0] == a[N-1]){
        if(N == k){
            cout << "YES\n";
            for(int i = 0; i<N; i++){
                cout << a[i] <<" ";
            }
            cout << "\n";
            return;
        }
        else cout << "NO\n";
        return;
    }

    int idx = N-k;    
    if(idx>0 && a[idx-1] == a[N-1]){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(int i = idx; i<N; i++){
        cout << a[i] <<" ";
    }

    for(int i = idx-1; i>=0; i--){
        cout << a[i] <<" ";
    }
    cout << "\n";

    // cout << idx <<"\n";
    // for(int i = 0; i<N; i++){
    //     cout << a[i] <<" ";   
    // }
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}