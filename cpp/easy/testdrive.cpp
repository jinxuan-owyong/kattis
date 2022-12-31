// Test Drive
#include <iostream>

const std::string OUTPUT_ACCELERATED = "accelerated";
const std::string OUTPUT_BRAKED = "braked";
const std::string OUTPUT_CRUISED = "cruised";
const std::string OUTPUT_TURNED = "turned";

int main(void) {
    int a, b, c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    bool is_turned = (b > a && b > c) || (b < a && b < c);
    if (is_turned) {
        std::cout << OUTPUT_TURNED;
        return 0;
    }

    int dist_first = std::abs(b - a);
    int dist_second = std::abs(c - b);

    if (dist_second > dist_first) {
        std::cout << OUTPUT_ACCELERATED;
        return 0;
    }
    if (dist_second < dist_first) {
        std::cout << OUTPUT_BRAKED;
        return 0;
    }
    std::cout << OUTPUT_CRUISED;
    return 0;
}
