// Speed Limit
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while (cin >> N) {
        if (N == -1)
            break;
        int sum = 0, prev = 0, curr, sp;
        for (int i = 0; i < N; ++i) {
            cin >> sp >> curr;
            sum += sp * (curr - prev);
            prev = curr;
        }
        cout << sum << " miles\n";
    }
    return 0;
}
