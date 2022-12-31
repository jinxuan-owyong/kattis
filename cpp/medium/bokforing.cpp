// Accounting
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q, id = 0, base = 0;
    cin >> N >> Q;
    vi wealth(N + 1, 0), valid(N + 1, 0);
    string inst;
    int a, b, x;
    for (int i = 0; i < Q; ++i) {
        cin >> inst;
        if (inst == "SET") {
            cin >> a >> b;
            wealth[a] = b;
            valid[a] = id;
        }
        if (inst == "RESTART") {
            ++id;
            cin >> x;
            base = x;
        }
        if (inst == "PRINT") {
            cin >> a;
            cout << (valid[a] == id ? wealth[a] : base) << '\n';
        }
    }
    return 0;
}
