#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

ll k, l;
int n;

signed main()
{
    FASTIO;
    
    cin >> k >> l;
    cin >> n;

    vector<ll> w(n);
    for(int i = 0; i<n; i++){
        cin >> w[i];
    }
    
    ll cnt = 1;
    for(int i = 1; i<l; i++){
        cnt *= k;
        if(cnt > n){
            cout << "0\n";
            return 0;
        }
    }

    priority_queue<ll, vector<ll>, greater<>> pq;
    for(int i = 0; i<cnt; i++){
        pq.push(0);
    }
    for(int i = 0; i<n; i++){
        ll mn = pq.top();
        pq.pop();
        pq.push(mn+w[i]*(l-1));
    }

    cout << pq.top() << "\n";
    while(!pq.empty()){
        cout << pq.top() <<"!\n";
        pq.pop();
    }

    return 0;
}