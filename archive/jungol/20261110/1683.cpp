#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;

    int N = s.length();

    vector<int> temp;
    for(int i = N-1; i>=0; i-=2){
        int num = s[i]-'0';
        num += (i==0) ? 0 : (10*(s[i-1]-'0'));
        
        temp.push_back(num%7);
    }


    array<int, 3> three = {};
    int cur = 2;
    for(int e: temp){
        three[cur] += e;
        cur = (cur-1+3)%3;
    }

    three[0] %=7;
    three[1] %=7;
    three[2] %=7;

    int left = (10*three[0] + three[1])%7;
    int right = (10*three[1] + three[2])%7;
    int ans = (right - left+7)%7;

    cout << ans << "\n";
}

int main()
{
    FASTIO;
    
    solve();
    solve();
    solve();
    return 0;
}