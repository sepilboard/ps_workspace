#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for(int i = 0; i<n; i++){
        int val;
        cin >> val;
        a[i] = {val, i&1};
    }

    sort(a.begin(), a.end());
    int last = -1;
    vector<pair<int, int>> ra;
    for(int i = 0; i<n; i++){
        if(last != a[i].second){
            last = a[i].second;
            continue;
        }
        ra.push_back(a[i]);
    }

    sort(ra.begin(), ra.end(), greater<>());
    if(ra.empty()){
        cout << "YES\n";
        return;    
    }

    if(last == ra[0].second){
        cout << "NO\n";
        return;
    }
    
    for(int i = 1; i<ra.size(); i++){
        if(ra[i-1].second == ra[i].second){
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