// Jackpot
#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<int, int> umapii;

void insertOrIncrement(umapii& dest, int k) {
    if (dest.find(k) != dest.end())
        ++dest[k];
    else
        dest[k] = 1;
}

umapii primeFactors(int n) {
    umapii res = {{1, 1}};
    while (n % 2 == 0) {  // even
        insertOrIncrement(res, 2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {  // odd
        while (n % i == 0) {
            insertOrIncrement(res, i);
            n = n / i;
        }
    }
    if (n > 2)
        insertOrIncrement(res, n);
    return res;
}

int main(void) {
    int n, w;
    cin >> n;
    while (n--) {
        cin >> w;
        umapii lcm;
        for (int i = 0; i < w; ++i) {
            int temp;
            cin >> temp;
            umapii factors = primeFactors(temp);
            for (auto& [f, p] : factors) {
                if (lcm.find(f) == lcm.end() || p > lcm[f]) {
                    lcm[f] = p;
                }
            }
        };
        long long res = 1;
        for (auto& [f, p] : lcm) {
            if (res > 1e9)
                break;
            res *= pow(f, p);
        };
        res <= 1e9 && cout << res << '\n';
        res > 1e9 && cout << "More than a billion.\n";
    }

    return 0;
}
