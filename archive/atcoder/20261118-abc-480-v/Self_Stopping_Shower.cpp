#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    int N, K, T;
    cin >> N >> K >> T;

    vector<int> a(N+1);
    for(int i = 0; i<N; i++){
        cin >> a[i];
    }
    a[N] = T;

    sort(a.begin(), a.end());
    
    ll cur = K;
    ll cnt = 0LL;
    if(a[0] != 0) cnt++;
    for(int i = 0; i<=N; i++){
        if(a[i] > T) break;
        if(cur<a[i]){
            ll diff = a[i]-cur;
            ll ccnt = (diff+K-1)/K;
            cur = max(cur+ccnt*K, 1LL*a[i]+K);

            cnt += ccnt;
        }
        else{
            cur = max(cur, 1LL*a[i]+K);
        }
        // cout << i << ": " << cnt <<"," <<cur <<"\n";
    }

    cout << cnt << "\n";
    
    return 0;
}