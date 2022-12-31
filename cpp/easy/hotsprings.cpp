// Hot Springs
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    sort(t.begin(), t.end());

    int i = 1, j = n - 2;
    stack<int> output;  // store largest to smallest difference
    output.push(t[0]);
    output.push(t[n - 1]);

    while (n > 2 && i != j) {  // n == 2 special case, i will never be equal j
        int diff_i = abs(t[i] - output.top());
        int diff_j = abs(t[j] - output.top());
        if (diff_i > diff_j) {  // push the larger difference
            output.push(t[i]);
            ++i;
        } else {
            output.push(t[j]);
            --j;
        }
    }
    if (n > 2)  // remaining number when i == j
        output.push(t[i]);

    while (output.size() > 0) {
        cout << output.top() << ' ';
        output.pop();
    }

    return 0;
}
