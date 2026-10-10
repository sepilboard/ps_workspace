#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int muti(int a, int b){
    return a*b;
}

signed main()
{
    int(*func[3])(int, int);

    func[0] = [](int a, int b){
        return a+b;
    };
    func[1] = muti;
    func[2] = [](int a, int b){
        return a-b;
    };

    for(int i = 0; i<3; i++){
        int a, b;
        cin >> a >>b;
        cout << func[i](a, b) <<"\n";
    }
    
    vector<int(*)(int, int)> v;
    v.push_back([](int a, int b){return a+b;});
    v.push_back(muti);
    cout << v[0](1, 2) << "\n";
    cout << v[1](1, 2) << "\n";

    return 0;
}