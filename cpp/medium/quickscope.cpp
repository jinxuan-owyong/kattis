// Quickscope
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

const string OPEN_BRACE = "{";
const string CLOSE_BRACE = "}";
const string DECLARE = "DECLARE";
const string TYPEOF = "TYPEOF";
const string UNDECLARED = "UNDECLARED";
const string MULTI_DEC = "MULTIPLE DECLARATION";

class Block {
public:
    int id;
    unordered_map<string, string> variables;
    Block() : id(-1) {}
    Block(int i) {
        id = i;
    }
    bool isVariable(string name) {
        return variables.find(name) != variables.end();
    }
    // returns true if insertion success, false otherwise
    bool insert(string name, string type) {
        // insert variable if not yet declared
        if (isVariable(name))
            return false;
        variables.insert(pair(name, type));
        return true;
    }
    string getVariable(string name) {
        if (!isVariable(name))
            return UNDECLARED;
        return variables[name];
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, currScope = 0, id = 0;
    cin >> N;
    unordered_map<string, list<int>> appearances;
    map<int, Block> blocks = {{0, Block(0)}};
    set<int> invalid;
    unordered_map<int, int> scopeID = {{0, 0}};

    for (int i = 0; i < N; ++i) {
        string instruction;
        cin >> instruction;

        if (instruction == OPEN_BRACE) {
            ++id;
            ++currScope;
            Block new_block(id);
            blocks.insert(pair(currScope, new_block));
            scopeID.insert(pair(id, currScope));
        } else if (instruction == CLOSE_BRACE) {
            invalid.insert(blocks[currScope].id);
            blocks.erase(currScope);
            --currScope;
        } else if (instruction == DECLARE) {
            string name, type;
            cin >> name >> type;
            // assumption: required block already exists
            bool inserted = blocks[currScope].insert(name, type);
            if (!inserted) {  // multiple declarations
                cout << MULTI_DEC << '\n';
                break;
            } else {
                // keep track of occurrences
                if (appearances.find(name) != appearances.end()) {
                    appearances[name].push_back(blocks[currScope].id);
                } else {
                    list<int> temp = {blocks[currScope].id};
                    appearances[name] = temp;
                }
            }
        } else if (instruction == TYPEOF) {
            string name;
            cin >> name;
            auto res = appearances.find(name);
            if (res == appearances.end()) {  // variable has never been declared
                cout << UNDECLARED << '\n';
                continue;
            }
            // output variable type from its most recent valid declaration
            bool found = false;
            for (auto it = appearances[name].crbegin(); it != appearances[name].crend(); ++it) {
                if (invalid.find(*it) == invalid.end()) {
                    int& scope = scopeID[*it];
                    cout << blocks[scope].getVariable(name) << '\n';
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << UNDECLARED << '\n';
        }
    }
    return 0;
}
