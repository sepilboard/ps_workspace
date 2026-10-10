#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



signed main()
{
    vector<function<int(int, int)>> func(3);
    func[0] = [&](int a, int b){
        return a+b;
    };
    func[1] = [&](int a, int b){
        return a*b;
    };
    func[2] = [&](int a, int b){
        return a-b;
    };

    for(int i = 0; i<3; i++){
        int a, b;
        cin >> a >> b;
        cout << func[i](a, b) <<"\n";
    }
    
    return 0;
}