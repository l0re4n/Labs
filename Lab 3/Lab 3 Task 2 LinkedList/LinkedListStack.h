#include <ostream>
#include <string.h>

template<typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(T x) : val(x), next(nullptr) {}
    ListNode(T x, ListNode* next) : val(x), next(next) {}
};

template <typename T>
class LinkedListStack {
private:
    ListNode<T>* first;
    size_t size;
    int capacity;
    int n;
public:
    LinkedListStack(int capacity) {
        this->capacity = capacity;
        first = nullptr;
        size = 0;
        n = 0;
    }
    ~LinkedListStack() {
        ListNode<T>* cur = first;
        while (cur) {
            cur = cur->next;
            delete first;
            first = cur;
        }
    }
    bool empty() { return first == nullptr; }
    void push(T item) {
        if(capacity == n) {
            std::cout << "Stack is full\n";
            return;
        }
        first = new ListNode<T>(item, first);
        n++;
    }
    T pop() {
        if (first == nullptr) {
            T temp;
            memset(&temp, 0, sizeof(T));
            std::cout << "No elements\n";
            return temp;
        }
        T temp = first->val;
        ListNode<T>* cur = first;
        first = first->next;
        delete cur;
        n--;
        return temp;
    }
    T top() {
        if (first == nullptr) {
            T temp;
            memset(&temp, 0, sizeof(T));
            std::cout << "No elements\n";
            return temp;
        }
        return first->val;
    }
    friend std::ostream& operator<<(std::ostream& os, LinkedListStack<T>& st) {
        if (st.first == nullptr) {
            os << "No elements";
            return os;
        }
        os << "Stack: ";
        ListNode<T>* cur = st.first;
        while (cur) {
            os << cur->val << ' ';
            cur = cur->next;
        }
        return os;
    }
};