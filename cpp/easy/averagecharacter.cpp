// Average Character
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int t = 0;
    for (char c : s) t += (int)c;
    cout << (char)(t / s.size());
    return 0;
}
