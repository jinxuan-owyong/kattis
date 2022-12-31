// Mjehuric
#include <iostream>

const int NUM_PIECES = 5;

template <typename T>
void print_arr(T arr[], int n, char delim = ' ') {
    for (int i = 0; i < n; ++i) std::cout << arr[i] << delim;
    std::cout << '\n';
}

int main(void) {
    int seq[5]{0};
    for (int i = 0; i < NUM_PIECES; ++i) std::cin >> seq[i];

    bool sorted = false;
    while (!sorted) {
        // swap positions if necessary
        for (int i = 0; i < NUM_PIECES - 1; ++i) {
            if (seq[i] > seq[i + 1]) {
                std::swap(seq[i], seq[i + 1]);
                print_arr(seq, NUM_PIECES);
            }
        }

        // check if array is sorted
        for (int i = 0; i < NUM_PIECES - 1; ++i) {
            if (seq[i] > seq[i + 1]) {
                sorted = false;
                break;
            }
            sorted = true;
        }
    }

    return 0;
}
