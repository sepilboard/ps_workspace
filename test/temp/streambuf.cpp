#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main() {
    ofstream file("output.txt");

    streambuf* original = cout.rdbuf();

    cout.rdbuf(file.rdbuf());

    cout << "Hello\n";

    cout.rdbuf(original);

    cout << "World\n";

    return 0;
}