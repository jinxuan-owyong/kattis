// Jumbo Javelin
#include <iostream>

int main(void) {
    int n;  // number of steel rods
    std::cin >> n;

    float sum_fused_length = 0;

    // add fused length for each rod
    for (int i = 0; i < n; ++i) {
        float input_length;
        std::cin >> input_length;

        if (i != n - 1)
            sum_fused_length += (input_length - 1);
        else
            sum_fused_length += input_length;
    }

    std::cout << sum_fused_length;

    return 0;
}
