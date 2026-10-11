#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<char> s(n+1);

    for(int i = 1; i<=n; i++){
        cin >> s[i];
    }

    int cur = 0;
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(s[i] == 'S'){
            cur = 0;
        }
        else{
            cur++;
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
    
    return 0;
}