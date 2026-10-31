#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    
    int N;
    cin >> N;
    
    vector<int> a(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i]; 
    }

    vector<ll> psum(N+1);
    a[0] = a[1];
    for(int i = 1; i<=N; i++){
        psum[i] = psum[i-1] + (a[i]-a[i-1])/2;
    }

    // for(int i = 1; i<=N; i++){
    //     cout << psum[i] - psum[i] <<" ";   
    // }cout << "\n";

    for(int i = 1; i<=N; i++){
        ll ans = 1e+18;
        if(i == 1 || i == N){
            cout << psum[N] <<"\n";
            continue;
        }

        ans = min(ans, max(psum[i], psum[N]-psum[i-1]));
        ans = min(ans, max(psum[i+1], psum[N]-psum[i]));

        cout << ans <<"\n";
    }
    
    
    return 0;
}