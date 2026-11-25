#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void qry(int N)
{
    string s = "";
    for(int i = 0; i<N; i++){
        s.push_back('+');
        s.push_back('-');
        s.push_back('-');
    }

    cout << s << endl;
    cout.flush();
}

void solve()
{
    int N;
    cin >> N;
    
    qry(N);
    int k;
    cin >> k;

    if(k == -1) return;

    cout << N+((k+2)/3) << endl;
    cout.flush();
}

signed main()
{
    // FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}