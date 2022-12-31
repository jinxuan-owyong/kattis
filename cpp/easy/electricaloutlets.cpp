// Electrical Outlets
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    while (N--) {
        int K, sum = 0, x;
        cin >> K;
        for (int i = 0; i < K; ++i) {
            cin >> x;
            sum += x - 1;
        }
        cout << sum + 1 << '\n';
    }
    return 0;
}
