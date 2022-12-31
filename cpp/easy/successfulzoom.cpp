// Successful Zoom
#include <cmath>
#include <iostream>
#include <vector>

const std::string ABORT = "ABORT!";

int main(void) {
    int n;
    std::cin >> n;
    std::vector<uint32_t> sales(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> sales[i];
    }

    int k = -1;
    for (int i = 1; i < n + 1; ++i) {
        if (k >= 0)
            break;
        int q = n / i;  // maximum number of iterations needed for current i

        uint32_t& prev = sales[i - 1];
        // loop through x_k, x_2k, ..., x_qk
        for (int j = 2; j < q + 1; ++j) {
            uint32_t& curr = sales[(i * j) - 1];
            if (curr <= prev)  // decreasing
                break;
            if (j == q)
                k = i;
            // increasing
            prev = curr;
        }
    }

    k >= 0 && std::cout << k;
    k < 0 && std::cout << ABORT;

    return 0;
}
