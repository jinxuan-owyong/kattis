// Reverse
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    for (int i = n - 1; i >= 0; --i) cout << d[i] << '\n';
    return 0;
}