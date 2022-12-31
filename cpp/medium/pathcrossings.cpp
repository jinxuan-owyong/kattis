// Path Crossings
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

const int DISTANCE_THRESHOLD = 1000;  // mm
const int TIME_WINDOW = 10;
const int WINDOW_LIMIT = 5;
const float EPSILON = 0.0001f;

class Ping {
public:
    int p, x, y, t;
    Ping(int pi, int xi, int yi, int ti) {
        p = pi;
        x = xi;
        y = yi;
        t = ti;
    };
    static float calcDist(Ping& a, Ping& b) {
        int x = b.x - a.x;  // x2 - x1
        int y = b.y - a.y;  // y2 - y1
        // calculate euclidean distance
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    }
    bool crossedPath(Ping& target) {
        if (this->p == target.p)
            return false;
        float dist = calcDist(*this, target);
        return dist < DISTANCE_THRESHOLD ||
               fabs(dist - DISTANCE_THRESHOLD) < EPSILON;
    }
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int P, N;
    std::cin >> P >> N;
    std::vector<Ping> db;
    for (int i = 0; i < N; ++i) {
        int p, x, y, t;
        std::cin >> p >> x >> y >> t;
        Ping temp = Ping(p, x, y, t);
        db.push_back(temp);
    }

    std::sort(db.begin(), db.end(), [](Ping& a, Ping& b) {
        return a.t < b.t;
    });

    std::map<int, std::set<int>> crossedPairs;

    for (int i = 0; i < N; ++i) {
        int count = 0;
        for (int j = i + 1; j < N; ++j) {
            if (db[j].t - db[i].t > TIME_WINDOW ||  // exceeding 10 second window
                count == WINDOW_LIMIT)              // sufficient pings
                break;

            // check if the player at t = i crossed path with t = j
            bool crossed = (db[i].crossedPath(db[j]));
            if (crossed) {
                int smaller = std::min(db[j].p, db[i].p);
                int larger = std::max(db[j].p, db[i].p);
                auto& crossers = crossedPairs[smaller];
                crossers.insert(larger);
                ++count;
            }
        }
    }

    // print crosses
    int C = 0;
    for (int player = 1; player <= P; ++player) {
        auto crosses = crossedPairs[player];
        C += crosses.size();
    }
    std::cout << C << '\n';

    for (int player = 1; player <= P; ++player) {
        auto crosses = crossedPairs[player];
        // sets are sorted in ascending order by default
        for (auto& x : crosses) {
            std::cout << player << ' ' << x << '\n';
        }
    }

    return 0;
}
