// Social Distancing
#include <iostream>
#include <vector>

int num_socially_distanced_seats(int n) {
    if (n <= 2)
        return 0;
    if (n % 2 == 0)
        return (n - 2) / 2;
    return (n - 2) / 2 + 1;
}

int find_available_seats(std::vector<int>& occupied, int total_seats) {
    int available = 0;
    // get first two occupied seats
    auto i = occupied.begin();
    auto j = occupied.size() == 1 ? i : i + 1;

    // count seats between the "first" and "last" occupied seats
    while (i != occupied.end() && i != j) {
        int num_seats = *j - *i - 1;
        available += num_socially_distanced_seats(num_seats);

        i = j;
        if (j == occupied.end())
            j = occupied.begin();
        else
            ++j;
    }

    // count seats between "last" and "first" occupied seats
    int seats_around = (occupied.front() - 1) + (total_seats - occupied.back());
    available += num_socially_distanced_seats(seats_around);

    return available;
}

int main(void) {
    // read input
    int s, n;
    std::cin >> s;
    std::cin >> n;
    std::vector<int> occupied;
    for (int i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        occupied.push_back(temp);
    }

    // check if max capacity is reached
    int max_capacity = s / 2;
    if (n >= max_capacity) {
        std::cout << 0;
        return 0;
    }

    // find available seats
    int additional_seats = find_available_seats(occupied, s);
    std::cout << additional_seats;

    return 0;
}
