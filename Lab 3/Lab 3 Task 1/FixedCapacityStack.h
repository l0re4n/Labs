#include <iostream>
#include <string.h>


template <typename T>
class FixedCapacityStack {
private:
    T* arr;
    int n;
    int capacity;
public:
    FixedCapacityStack(int capacity) {
        this->capacity = capacity;
        arr = new T[capacity];
        n = 0;
    }
    ~FixedCapacityStack() {
        delete[] arr;
    }
    bool empty() { return n == 0; }
    bool full() { return n == capacity; }
    void push(T item) {
        if (n == capacity) {
            std::cout << "Stack is full\n";
            return;
        }
        arr[n++] = item;
    }
    T pop() {
        if (n == 0) {
            T temp;
            memset(&temp, 0, sizeof(T));
            std::cout << "No elements\n";
            return temp;
        }
        return arr[--n];
    }
    T top() { 
        if (n == 0) {
            T temp;
            memset(&temp, 0, sizeof(T));
            std::cout << "No elements\n";
            return temp;
        }
        return arr[n - 1];
    }
    friend std::ostream& operator<<(std::ostream& os, FixedCapacityStack& st) {
        if (st.n == 0) {
            os << "No elements\n";
            return os;
        }
        os << "Stack: ";
        for (int i = st.n - 1; i >= 0; --i) {
            os << st.arr[i] << ' ';
        }
        os << '\n';
        return os;
    }
};