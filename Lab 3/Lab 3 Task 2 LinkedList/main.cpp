#include <iostream>
#include "LinkedListStack.h"
#define type string

using namespace std;

int main() {
    LinkedListStack<type>* stack = new LinkedListStack<type>(4);
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
        /*
        case 'f': // full
            if (stack->full()) cout << "Stack is full\n";
            else cout << "Stack is not full\n";
            break;
        */
        case 'd': // pop (delete)
            input = stack->pop();
            cout << input << endl;
            break;
        case 'g': // top (get top)
            input = stack->top();
            cout << input << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}