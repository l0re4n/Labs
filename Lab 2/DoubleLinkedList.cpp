#include <iostream>
#define type string
using namespace std;

template<typename T>
struct DoubleListNode // Double-Linked ListNode
{
	T val;
	DoubleListNode<T>* next;
	DoubleListNode<T>* prev;
	DoubleListNode(T val) : val(val), prev(nullptr), next(nullptr) {}
	DoubleListNode(T val, DoubleListNode<T>* prev, DoubleListNode<T>* next) : val(val), prev(prev), next(next) {}
};

template<typename T>
class DoubleLinkedList {
public:
	DoubleLinkedList() : head(nullptr), rhead(nullptr), size(0), reversed(false) {}
	size_t get_size() { return size; }
	void add_at_head(T val);
	void add_at_tail(T val);
	void print_list();
	void reverse();
	void add_at_index(size_t index, T val);

private:
	DoubleListNode<T>* head;
	DoubleListNode<T>* rhead;
	size_t size;
	bool reversed;
};

template<typename T>
void DoubleLinkedList<T>::add_at_head(T val) {
	if (size == 0) {
		head = new DoubleListNode<T>(val, nullptr, nullptr);
		rhead = head;
		++size;
	}
	else if (!reversed) {
		DoubleListNode<T>* temp = new DoubleListNode<T>(val, nullptr, head);
		head->prev = temp;
		head = temp;
		++size;
	}
	else {
		DoubleListNode<T>* temp = new DoubleListNode<T>(val, rhead, nullptr);
		rhead->next = temp;
		rhead = temp;
		++size;
	}
}

template<typename T>
void DoubleLinkedList<T>::add_at_tail(T val) {
	if (size == 0) {
		head = new DoubleListNode<T>(val, nullptr, nullptr);
		rhead = head;
		++size;
	}
	else if (!reversed) {
		DoubleListNode<T>* temp = new DoubleListNode<T>(val, rhead, nullptr);
		rhead->next = temp;
		rhead = temp;
		++size;
	}
	else {
		DoubleListNode<T>* temp = new DoubleListNode<T>(val, nullptr, head);
		head->prev = temp;
		head = temp;
		++size;
	}
}

template<typename T>
void DoubleLinkedList<T>::print_list() {
	if (size == 0) cout << "No elements in list\n";
	else {
		if (!reversed) {
			DoubleListNode<T>* cur = head;
			cout << "Elements: ";
			while (cur) {
				cout << cur->val << ' ';
				cur = cur->next;
			}
			cout << endl;
		}
		else {
			DoubleListNode<T>* cur = rhead;
			cout << "Elements: ";
			while (cur) {
				cout << cur->val << ' ';
				cur = cur->prev;
			}
			cout << endl;
		}
	}
}

template<typename T>
void DoubleLinkedList<T>::reverse() {
	reversed = !reversed;
}

template<typename T>
void DoubleLinkedList<T>::add_at_index(size_t index, T val) {
	if (index > size) {
		cout << "Index is larger than the size=" << size << "\n";
		return;
	}
	if (index == 0) {
		this->add_at_head(val);
		return;
	}
	if (index == size) {
		this->add_at_tail(val);
		return;
	}
	if (!reversed) {
		DoubleListNode<T>* prev = head;
		DoubleListNode<T>* cur = prev->next;
		size_t pos = 1;
		while (pos < index) {
			prev = cur;
			cur = cur->next;
			++pos;
		}
		prev->next = new DoubleListNode<T>(val, prev, cur);
		cur->prev = prev->next;
	}
	else {
		DoubleListNode<T>* prev = rhead;
		DoubleListNode<T>* cur = prev->prev;
		size_t pos = 1;
		while (pos < index) {
			prev = cur;
			cur = cur->prev;
			++pos;
		}
		prev->prev = new DoubleListNode<T>(val, cur, prev);
		cur->next = prev->prev;
	}
	++size;
}

int main() {
	type arr[] = { "fqef1", "fqef2", "fegqe3", "feggwe4", "fegqqe5" };
	DoubleLinkedList<type>* obj = new DoubleLinkedList<type>();
	obj->print_list();
	for (type val : arr) {
		obj->add_at_head(val);
	}
	obj->print_list();
	obj->reverse();
	cout << "Reversing\n";
	obj->print_list();

	cout << "Add at index 2\n";
	obj->add_at_index((size_t)2, "fqefq6");
	obj->print_list();

	return 0;
}