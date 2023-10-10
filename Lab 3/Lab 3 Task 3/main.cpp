#include <iostream>
#include <string>
#include "FixedCapacityStack.h"

using namespace std;

int main() {
    string input;
    cin >> input;
    if (input.size() & 1) {
        cout << "NO\n";
        return 0;
    };
    FixedCapacityStack<char>* stack = new FixedCapacityStack<char>(input.size());
    bool res = true;
    for (char c : input) {
        if (!res) break;
        if (c == '(' || c == '[' || c == '{') stack->push(c);
        else {
            if (stack->empty()) {
                res = false;
                break;
            }
            switch (stack->top())
            {
            case '(':
                if (c == ')') stack->pop();
                else res = false;
                break;
            case '[':
                if (c == ']') stack->pop();
                else res = false;
                break;
            case '{':
                if (c == '}') stack->pop();
                else res = false;
                break;
            }
        }
    }
    if (stack->empty() && res) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}