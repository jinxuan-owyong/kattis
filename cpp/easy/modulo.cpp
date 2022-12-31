// Modulo
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int d, N = 10;
    unordered_set<int> res;
    while (N--) {
        cin >> d;
        res.insert(d % 42);
    }
    cout << res.size();
    return 0;
}
