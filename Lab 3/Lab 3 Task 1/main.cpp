#include <iostream>
#include "FixedCapacityStack.h"
#define type string

using namespace std;

int main() {
    FixedCapacityStack<type>* stack = new FixedCapacityStack<type>(10);
    bool work = true;
    char c;
    type num;
    while (work) {
        cin >> c;
        switch (c)
        {
        case 'q': // quit
            work = false;
            delete stack;
            break;
        case 'a': // add
            cin >> num;
            stack->push(num);
            break;
        case 'p': // print
            cout << *stack;
            break;
        case 'e': // empty
            if (stack->empty()) cout << "Stack is empty\n";
            else cout << "Stack is not empty\n";
            break;
        case 'f': // full
            if (stack->full()) cout << "Stack is full\n";
            else cout << "Stack is not full\n";
            break;
        case 'd': // pop (delete)
            num = stack->pop();
            cout << num << endl;
            break;
        case 'g': // top (get top)
            num = stack->top();
            cout << num << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}