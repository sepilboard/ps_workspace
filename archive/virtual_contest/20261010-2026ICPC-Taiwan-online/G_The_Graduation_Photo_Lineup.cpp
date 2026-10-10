#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

signed main()
{
    FASTIO;

    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> s(n);
    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = 0; i<n; i++) cin >> s[i];

    sort(a.begin(), a.end());
    sort(s.begin(), s.end());
    
    vector<pair<int, int>> ans(n);

    for(int i = 0; i<n; i++){
        if(i-s[i]<0){
            cout << "-1\n";
            return 0;
        }
        ans[i] = {i-s[i], a[i]};
    }

    sort(ans.begin(), ans.end(), [](pair<int,int> &a, pair<int, int>b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    for(int i = 0; i<n; i++){
        cout << ans[i].second <<" ";
    }
    
    
    return 0;
}