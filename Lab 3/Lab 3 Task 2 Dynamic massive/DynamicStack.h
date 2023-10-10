#include <iostream>
#include <string.h>


template <typename T>
class DynamicStack {
private:
    T* arr;
    int n;
    int capacity;
public:
    DynamicStack() {
        this->capacity = 8;
        arr = new T[8];
        n = 0;
    }
    DynamicStack(int capacity) {
        this->capacity = capacity;
        arr = new T[capacity];
        n = 0;
    }
    ~DynamicStack() {
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


    void resize(size_t capacity) { // Pochito
        if (capacity == this->capacity) return; // (O(1))
        if (capacity < this->n) { // (O(1))
            T* temp = new T[capacity]; // КОПИ (O(1))
            memcpy(temp, this->arr + (this->n - capacity), sizeof(T) * capacity); // (O(N))
            delete arr; // deleting old array (O(1))
            arr = temp; // assigning new array to array (O(1))
            n = capacity; // PON (O(1))
        }
        else {
            T* temp = new T[capacity]; //(O(1)) 
            memcpy(temp, this->arr, sizeof(T) * capacity); // (O(N))
            delete arr; // (O(1))
            arr = temp; // (O(1))
        }
        this->capacity = capacity; // (O(1))
        // MEGA FAST POCHTI LINEAR
    }











    
    friend std::ostream& operator<<(std::ostream& os, DynamicStack& st) {
        if (st.n == 0) {
            os << "No elements";
            return os;
        }
        os << "Stack: ";
        for (int i = st.n - 1; i >= 0; --i) {
            os << st.arr[i] << ' ';
        }
        return os;
    }
};