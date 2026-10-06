#include <bits/stdc++.h>
using namespace std;

vector<int> makeTable(string pattern)
{
    int n = pattern.size();
    vector<int> table(n, 0);
    for(int i = 1, j = 0; i<n; i++){
        while(j>0 && pattern[i] != pattern[j]) j = table[j-1];
        if(pattern[i] == pattern[j]) table[i] = ++j;
    }
    return table;
}

int KMP(string all, string pattern)
{
    int ans = 0;
    vector<int> table = makeTable(pattern);
    int n = all.size();
    int m = pattern.size();
    
    for(int ti = 0, j = 0; ti<2*n-1; ti++){
        int i = ti%n;
        while(j>0 && all[i] != pattern[j]) j = table[j-1];
        if(all[i] == pattern[j]){
            if(j == m-1){
                ans++;
                j = table[j];
            }
            else j++;
        }
    }

    return ans;
}