// Code to Save Lives
#include <bits/stdc++.h>
using namespace std;

int ndntoi(string s) {
    int sum = 0, mul = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == ' ')
            continue;
        sum += (s[i] - '0') * mul;
        mul *= 10;
    }
    return sum;
}

int main(void) {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        int x = ndntoi(a), y = ndntoi(b);
        int z = x + y;

        list<int> d;
        while (z > 0) {
            d.push_front(z % 10);
            z /= 10;
        }

        for (int& x : d) cout << x << ' ';
        cout << '\n';
    }
}
