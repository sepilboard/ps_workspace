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

    int ans = 0;
    for(int i = N-1; i>0; i--){
        if(a[i-1]>a[i]){
            ans = i;
            break;
        }
    }

    cout << ans <<"\n";
    
    return 0;
}