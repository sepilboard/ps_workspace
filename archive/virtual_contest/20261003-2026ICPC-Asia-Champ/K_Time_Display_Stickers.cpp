#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<>> one_pq;
    priority_queue<int, vector<int>, greater<>> five_pq;
    priority_queue<int, vector<int>, greater<>> six_pq;
    
    for(int i = 0; i<n; i++){
        char c;
        cin >> c;
        int val = c-'0';
        if(val > 5){
            six_pq.push(val);
        }
        else if(val > 1){
            five_pq.push(val);
        }
        else{
            one_pq.push(val);
        }
    }

    int ans = 0;
    while(true){
        int fhour;
        int shour;
        int fmin;
        int smin;

        // 시간 첫번쨰
        if(!one_pq.empty()){
            fhour = one_pq.top(); one_pq.pop();
            if(fhour == 0){
                if(!six_pq.empty()){
                    shour = six_pq.top(); six_pq.pop();
                }
                else if(!five_pq.empty()){
                    shour = five_pq.top(); five_pq.pop();
                }
                else if(!one_pq.empty()){
                    shour = one_pq.top(); one_pq.pop();
                }
                else break;
            }
            else if(fhour == 1){
                if(!one_pq.empty()){
                    shour = one_pq.top(); one_pq.pop();
                }
                else break;
            }
            else break;
        }
        else break;

        // 분 첫번째
        if(!five_pq.empty()){
            five_pq.pop();
        }
        else if(!one_pq.empty()){
            one_pq.pop();
        }
        else break;

        // 분 두번째
        if(!six_pq.empty()){
            six_pq.pop();
        }
        else if(!five_pq.empty()){
            five_pq.pop();
        }
        else if(!one_pq.empty()){
            one_pq.pop();
        }
        else break;

        ans++;
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