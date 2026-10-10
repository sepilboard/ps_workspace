#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



signed main()
{
    FASTIO;
    string b;
    cin >> b;

    vector<char> unq1;
    for(int i = 0; i<b.size(); i++){
        if(unq1.empty() || unq1.back() != b[i]) unq1.push_back(b[i]);
    }
    cout.write(unq1.data(), unq1.size()) << "\n";
    
    string unq2 = b;
    unq2.erase(unique(unq2.begin(), unq2.end()), unq2.end());
    cout << unq2;

    return 0;
}