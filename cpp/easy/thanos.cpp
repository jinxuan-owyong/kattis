// Thanos
#include <iostream>

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        long P, R, F;
        std::cin >> P >> R >> F;

        long num_years = 0;
        while (P <= F) {
            ++num_years;
            P *= R;
        }

        std::cout << num_years << '\n';
    }

    return 0;
}
