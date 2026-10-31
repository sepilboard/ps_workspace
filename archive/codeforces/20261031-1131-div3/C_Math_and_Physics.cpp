#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> b(N);
    int sum = 0;
    for(int i = 0; i<N; i++){
        cin >> a[i];   
        b[i] = a[i];
        sum += a[i];
    }   

    b.erase(unique(b.begin(), b.end()), b.end());

    if(b.size()>3){
        cout << sum-1 <<"\n";
        return;
    }

    if(b.size() == 3){
        if(a[0] != 1 && a[1] == 1 && a[N-2] == 1 && a[N-1] != 1){
            cout << b[0]+b[2]-1 <<"\n";
        }
        else{
            cout << sum-1 <<"\n";
        }
    }
    else if(b.size() == 2){
        if((a[0] != 1 && a[1] == 1) || (a[N-2] == 1 && a[N-1] != 1)){
            if(b[0] == 1) cout << b[1] <<"\n";
            else cout << b[0] <<"\n";
        }
        else{
            cout << sum-1 <<"\n";
        }
    }
    else if(b.size() == 1){
        if(b[0] == 1){
            cout << "-1\n";
            return;
        }
        else{
            cout << sum-1 <<"\n";
            return;
        }
    }
    

}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}