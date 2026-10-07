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
    int pprv = -1;
    bool evict = false;
    int last = -1;
    vector<pair<int, int>> ra;
    for(int i = 1; i<n; i++){
        if(evict){
            if(pprv == a[i].second){
                cout << "NO\n";
                return;
            }
            
            evict = false;
        }
        else{
            if(a[i-1].second == a[i].second){
                ra.push_back(a[i]);
                evict = true;
            }
        }

        pprv = a[i-1].second;
        if(evict) last = a[i-1].second;
        else last = a[i].second;
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
        if(a[i-1].second == a[i].second){
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