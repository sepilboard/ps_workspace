#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> range(m);
    for(int i = 0; i<m; i++){
        cin >> range[i].first >> range[i].second;
    }

    sort(range.begin(), range.end());
    int mnl = range[0].first;
    int mnr = range[0].second;
    int mxl = range[0].first;
    int mxr = range[0].second;

    vector<array<int, 4>> res;
    for(int i = 1; i<m; i++){
        auto[l, r] = range[i];

        if(l<mnr){
            mnl = max(mnl, l);
            mnr = min(mnr, r);
            mxl = min(mxl, l);
            mxr = max(mxr, r);
        }
        else{
            res.push_back({mnl, mnr, mxl, mxr});
            mnl = l;
            mnr = r;
            mxl = l;
            mxr = r;
        }
    }
    res.push_back({mnl, mnr, mxl, mxr});

    for(int i = 1; i<res.size(); i++){
        auto[prv_mnl, prv_mnr, prv_mxl, prv_mxr] = res[i-1];
        auto[mnl, mnr, mxl, mxr] = res[i];

        if(prv_mnr>=mxl || mnl<=prv_mxl){
            if(prv_mnr == prv_mxr && prv_mxr == mxl && mxl == mnl){
                continue;
            }
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}