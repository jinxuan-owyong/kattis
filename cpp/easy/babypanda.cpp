// Baby Panda
#include <iostream>

int main(void) {
    long n, m;
    std::cin >> n >> m;

    int num_sneezes = 0;
    while (m > 0) {
        if (m % 2 == 1) {
            ++num_sneezes;
            --m;
            continue;
        }
        m /= 2;
    }

    std::cout << num_sneezes;
    return 0;
}
