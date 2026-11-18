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
    for(int i = 0; i<N; i++){
        int rem = a[i]%10;

        switch (rem)
        {
        case 1:
        case 6:
            ans -= 1;
            break;

        case 2:
        case 7:
            ans -=2;
            break;

        case 3:
        case 8:
            ans +=2;
            break;

        case 4:
        case 9:
            ans +=1;
            break;
        
        default:
            break;
        }
    }

    cout << (-ans) <<"\n";
    
    return 0;
}