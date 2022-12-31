// Gear Changing
#include <algorithm>
#include <iostream>
#include <vector>

const std::string CONTINUE = "Ride on!";
const std::string CHANGE = "Time to change gears!";

int main(void) {
    int N, M, P;
    std::cin >> N >> M >> P;
    std::vector<int> gears_crank(N);
    std::vector<int> gears_back(M);
    for (int i = 0; i < N; ++i) std::cin >> gears_crank[i];
    for (int i = 0; i < M; ++i) std::cin >> gears_back[i];

    std::sort(gears_crank.begin(), gears_crank.end());
    std::sort(gears_back.begin(), gears_back.end());

    std::vector<float> cadences(N * M);
    for (int i = N - 1; i >= 0; --i) {
        float crank = gears_crank[i] * 1.0f;
        for (int j = 0; j < M; ++j) {
            int& back = gears_back[j];
            cadences.push_back(crank / back);
        }
    }

    std::sort(cadences.begin(), cadences.end(), std::greater<float>());

    for (int i = 1; i < N * M; ++i) {
        float pdiff = (cadences[i - 1] - cadences[i]) / cadences[i] * 100;
        if (pdiff > P) {
            std::cout << CHANGE;
            return 0;
        }
    }

    std::cout << CONTINUE;
    return 0;
}

// float prev_cadence = 0;
// // iterate from fastest to slowest speed
// for (int i = N - 1; i >= 0; --i) {  // iterate crank gears
//     for (int j = 0; j < M; ++j) {   // iterate back gears
//         std::cout << gears_crank[i] << ' ' << gears_back[j] << '\n';
//     }
// }
