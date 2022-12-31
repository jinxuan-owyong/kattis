// Building Pyramids
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, h = -1;
    cin >> N;
    if (N == 0) {
        cout << 0;
        return 0;
    }

    while (pow(h + 2, 2) <= N) {
        h += 2;
        N -= pow(h, 2);
    }

    cout << (h / 2) + 1;
    return 0;
}
