// Job Switching
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, x = 0;
    cin >> N;
    vector<int> a(N + 1, -1);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i) {
        while (a[i] != i) {
            swap(a[i], a[a[i]]);
            ++x;
        }
    }
    cout << x;
}