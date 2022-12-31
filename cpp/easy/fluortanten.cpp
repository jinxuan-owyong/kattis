// Fluortanten
#include <iostream>
#include <vector>

const int BJORN = 0;

template <typename T>
void swap(std::vector<T>& vec, int i, int j) {
    T temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

long find_maximum_happiness(std::vector<int>& q) {
    // calculate happiness for original state
    long max = 0;
    int len = q.size();
    for (int i = 0; i < len; ++i) max += q[i] * (i + 1);

    long sum_front = max;
    long sum_back = 0;

    for (int zero_i = len - 1; zero_i >= 1; --zero_i) {
        // calculate happiness at current state
        sum_front -= q[zero_i - 1] * (zero_i);
        sum_back += q[zero_i - 1] * (zero_i + 1);

        long curr = sum_front + sum_back;
        if (curr > max)
            max = curr;

        // move 0 to the left
        swap(q, zero_i - 1, zero_i);
    }

    return max;
}

int main(void) {
    int n;
    std::cin >> n;
    std::vector<int> q(n, 0);
    std::vector<long> sum(n, 0);
    int zero_i;
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
        if (q[i] == BJORN)
            zero_i = i;
    }
    q.erase(q.begin() + zero_i);
    q.push_back(BJORN);

    std::cout << find_maximum_happiness(q);
    return 0;
}
