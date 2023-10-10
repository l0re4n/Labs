#include <iostream>
#include "DynamicStack.h"
#define type int
// string не будет работать потому что не имеет постоянного размера
// вместо string лучше использовать char*
using namespace std;

int main() {
    DynamicStack<type>* stack = new DynamicStack<type>(3);
    bool work = true;
    char c;
    type input;
    while (work) {
        cin >> c;
        switch (c)
        {
        case 'q': // quit
            work = false;
            delete stack;
            break;
        case 'a': // add
            cin >> input;
            stack->push(input);
            break;
        case 'p': // print
            cout << *stack << endl;
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
            input = stack->pop();
            cout << input << endl;
            break;
        case 'g': // top (get top)
            input = stack->top();
            cout << input << endl;
            break;
        case 'r': // resize
            int num;
            cin >> num;
            if (num < 0) {
                cout << "Cannot resize\n";
            }
            else {
                stack->resize(num);
            }
        default:
            break;
        }
    }
    return 0;
}