// Quality-Adjusted Life-Year
#include <iostream>

int main(void) {
    int n;  // number of periods
    std::cin >> n;

    float sum_qaly = 0;

    // calculate and add QALY of each period
    for (int i = 0; i < n; ++i) {
        float input_q;
        float input_y;
        std::cin >> input_q;
        std::cin >> input_y;

        sum_qaly += (input_q * input_y);
    }

    std::cout << sum_qaly;

    return 0;
}
