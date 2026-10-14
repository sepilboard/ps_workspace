#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;

    int cnt = 1;
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;
    bool flag4 = false;
    for(int i = 1; i<(int)s.size() - 1; i++){
        if(!flag1 && s[i-1] == '0' && s[i] == '1' && s[i+1] == '0'){
            flag1 = true;
            cnt++;
        }
        if(!flag1 && s[i-1] == '1' && s[i] == '0' && s[i+1] == '1'){
            flag1 = true;
            cnt++;
        }
        if(!flag2 && s[i-1] == '1' && s[i] == '1' && s[i+1] == '1'){
            flag2 = true;
            cnt++;
        }
        if(!flag2 && s[i-1] == '0' && s[i] == '0' && s[i+1] == '0'){
            flag2 = true;
            cnt++;
        }
    }   
    cout << cnt << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}