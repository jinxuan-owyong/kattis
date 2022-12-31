// Turn It Up!
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, vol = 7;
    cin >> n;
    cin.ignore();
    while (n--) {
        string inst;
        getline(cin, inst);
        if (inst == "Skru op!" && vol < 10)
            ++vol;
        if (inst == "Skru ned!" && vol > 0)
            --vol;
    }
    cout << vol;
    return 0;
}
