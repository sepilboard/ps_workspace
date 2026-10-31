#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    string s;
    cin >> s;
    
    int cnt = 0;
    for(char c: s){
        if(c == 'o'){
            cnt++;
        }
    }

    if(cnt%2){
        cout << "odd\n";
    }
    else{
        cout << "even\n";
    }
    
    return 0;
}