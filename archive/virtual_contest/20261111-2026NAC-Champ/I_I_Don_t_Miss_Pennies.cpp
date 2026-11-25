#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    
    int N;
    cin >> N;
    
    vector<int> a(N);
    for(int i = 0; i<N; i++){
        cin >> a[i];
    }
    
    vector<int> cnt(5, 0);
    for(int i = 0; i<N; i++){
        cnt[a[i]%5]++;
    }

    int ans = 0;
    ans -= cnt[1]; 
    ans -= 2*cnt[2]; 

    int use = min(cnt[3], cnt[4]);
    ans -= 2*use;

    cnt[3] -= use;
    cnt[4] -= use;
    
    ans -= cnt[3]/2;
    ans += 2*(cnt[3]%2);

    ans -= 2*(cnt[4]/3);
    ans += cnt[4]%3;

    cout << (-ans) <<"\n";
    
    return 0;
}