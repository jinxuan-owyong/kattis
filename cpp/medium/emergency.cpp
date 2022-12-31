// Emergency Contest Running
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, K;
    cin >> N >> K;
    if (K >= N - 1 || 2 * K >= N) {
        cout << N - 1 << '\n';
        return 0;
    }
    cout << (N - 1) % K + 1 + K << '\n';
    return 0;
}
