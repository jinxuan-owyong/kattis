// Working From Home
#include <cmath>
#include <iostream>
#include <queue>

int main(void) {
    int m, n, p;

    std::cin >> m;  // baseline
    std::cin >> p;  // target-adjust multiplier
    std::cin >> n;  // number of days worked

    std::queue<int> hours_worked;
    for (int i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        hours_worked.push(temp);
    }

    int target = m;
    int num_episodes = 0;
    while (hours_worked.size() > 0) {
        const int w = hours_worked.front();
        if (w >= target)
            ++num_episodes;

        // calculate new target
        target = ceil(m - (w - target) * p / 100.0f);

        hours_worked.pop();  // remove the first element
    }

    std::cout << num_episodes;
    return 0;
}
