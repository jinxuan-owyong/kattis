// Soda Slurper
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int e, f, c;
    cin >> e >> f >> c;
    int remain = e + f;
    int sum = 0;

    while (remain / c > 0) {
        int exchanged = remain / c;
        sum += exchanged;
        remain = remain % c;
        remain += exchanged;
    }

    cout << sum;
    return 0;
}
