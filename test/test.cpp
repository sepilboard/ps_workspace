#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

/**
 * @brief       간단한 설명
 * @param x     간단한 설명
 * @return      간단한 설명
 */
int func(int x)
{
    return x;
}

int main() {
    char c[5] = {'2', '3'};
    
    // vector<int> a = {0, 0, 0, 1, 1, 2, 3, 4, 5};
    vector<int> a = {0, 0, 0, 1, 1, 1, 0, 1, 0};
    string b = "000111010";
    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    // for(int e: a){
    //     cout << e << " ";
    // }
    cout << b;

    sort(a.begin(), a.end(), [](int a, int b){return true;});
    

    return 0;
}