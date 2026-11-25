#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int x, y, m;
    cin >> x >> y >> m;

    vector<char> s(m+1);
    for(int i = 1; i<=m; i++){
        cin >> s[i];   
    }

    vector<vector<vector<char>>> dp(m+1, vector<vector<char>>(x+m+1, vector<char>(y+m+1, false)));
    dp[0][x][y] = true;
    int ans = x+y;
    for(int i = 1; i<=m; i++){
        for(int j = 0; j<=x+m; j++){
            for(int k = 0; k<=y+m; k++){
                if(!dp[i-1][j][k]) continue;

                if(s[i] == '+'){
                    if(j>0){
                        dp[i][j-1][k+1] = true;
                        ans = max(ans, j-1+k+1);
                    }
                    if(k>0){
                        dp[i][j][k+1] = true;
                        ans = max(ans, j+k+1);
                    }
                }
                else{
                    if(j>0){
                        dp[i][j-1][k] = true;
                        ans = max(ans, j-1+k);
                    }
                    if(k>0){
                        dp[i][j+1][k-1] = true;
                        ans = max(ans, j+1+k-1);
                    }
                }
            }
        }
    }
    
    cout << ans << "\n";
}


signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}