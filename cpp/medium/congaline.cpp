// Conga Line
#include <iostream>
#include <list>
using namespace std;

class Person {
public:
    string name;
    string partner;
    list<Person>::iterator partner_it;

    Person(string n, string p) {
        name = n;
        partner = p;
    };

    void say_partner() {
        cout << partner << '\n';
    };
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    list<Person> line;
    for (int i = 0; i < N; ++i) {
        string first, second;
        cin >> first >> second;
        Person person_first = Person(first, second);
        Person person_second = Person(second, first);
        line.push_back(person_first);
        auto first_it = --line.end();
        line.push_back(person_second);
        auto second_it = --line.end();
        first_it->partner_it = second_it;
        second_it->partner_it = first_it;
    }

    string instructions;
    cin >> instructions;
    auto mic_holder = line.begin();  // host passes mic to the front of the line
    for (const auto& inst : instructions) {
        switch (inst) {
        case 'P': {  // yell partner's name
            mic_holder->say_partner();
            break;
        }
        case 'F': {  // pass to person in front
            --mic_holder;
            break;
        }
        case 'B': {  // pass to person behind
            ++mic_holder;
            break;
        }
        case 'C':
        case 'R': {
            auto prev_it = mic_holder;       // to erase
            Person prev = *mic_holder;       // move to back of line
            ++mic_holder;                    // only iterator of erased element is invalidated
            if (mic_holder == line.end()) {  // mic passed beyond last person
                mic_holder = line.begin();
            }

            auto pair_it = prev_it->partner_it;
            line.erase(prev_it);  // O(1)
            if (inst == 'R') {
                line.insert(line.end(), prev);
                pair_it->partner_it = --line.end();  // update position of inserted partner
            } else {                                 // 'C'
                auto insert_it = pair_it;
                ++insert_it;                      // insert behind partner
                line.insert(insert_it, prev);     // O(1)
                pair_it->partner_it = pair_it++;  // update position of inserted partner
            }
            break;
        }
        }
    }

    // output the new ordering of people in line
    cout << '\n';
    for (auto& person : line) {
        cout << person.name << '\n';
    }
    return 0;
}
