// Arrangement
#include <iostream>

int main(void) {
    int N, M;
    std::cin >> N >> M;
    int rem = M;
    int avg = M / N;
    while (rem > 0) {
        if ((rem % (avg + 1) == 0) && (M % N != 0))
            ++avg;
        for (int i = 0; i < avg; ++i) {
            std::cout << '*';
        }
        rem -= avg;
        std::cout << '\n';
    }
    return 0;
}
