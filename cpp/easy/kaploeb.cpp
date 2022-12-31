// Running Race
#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_map>

typedef struct {
    int time;
    int start_number;
    int laps;
} stats;

int mmss_to_ss(std::string t) {
    std::istringstream iss(t);
    std::string mm, ss;
    std::getline(iss, mm, '.');
    std::getline(iss, ss);
    return stoi(mm) * 60 + stoi(ss);  // output time in seconds
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int l, k, s;
    std::unordered_map<int, stats> timings;

    std::cin >> l >> k >> s;
    for (int i = 0; i < l; ++i) {
        int p;
        std::string mmss;
        std::cin >> p >> mmss;
        if (timings.find(p) == timings.end()) {  // first lap
            stats lap = {.time = mmss_to_ss(mmss), .start_number = p, .laps = 1};
            timings.insert(std::pair(p, lap));
        } else {  // subsequent laps
            timings[p].time += mmss_to_ss(mmss);
            ++timings[p].laps;
        }
    }

    auto cmp = [](stats a, stats b) {
        if (a.time == b.time) {
            return a.start_number > b.start_number;  // sort by start number, smaller has priority
        }
        return a.time > b.time;  // sort by timing, smaller has priority
    };
    // binary min heap
    std::priority_queue<stats, std::vector<stats>, decltype(cmp)>
        rankings(cmp);
    for (auto& p : timings) rankings.push(p.second);

    while (rankings.size() > 0) {
        auto& participant = rankings.top();
        if (participant.laps == k) {                        // check if race completed
            std::cout << participant.start_number << '\n';  // output start number
        }
        rankings.pop();
    }

    return 0;
}
