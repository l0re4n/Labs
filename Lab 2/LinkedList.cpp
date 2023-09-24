#include <iostream>
#define type int
using namespace std;

template<typename T>
struct ListNode {
	T val;
	ListNode* next;
	// Инициализация конструктора без параметров
	ListNode() : val(0), next(nullptr) {}
	// Конструктор с параметром данных
	ListNode(T x) : val(x), next(nullptr) {}
	// Конструктор с параметром данных и указателем на следующий элемент списка
	ListNode(T x, ListNode* next) : val(x), next(next) {}
};

template<typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr), size(0) {} 
	size_t get_size() { return size; }	// Получить размер списка
	void add_at_tail(T val);	// Добавить элемент в конец списка
	void add_at_index(size_t index, T val); // Добавить элемент по индексу
	void delete_at_index(size_t index);	// Удалить элемент по индексу
	void print_list(); // Вывести элементы списка
	void add_at_head(T val); // Добавить элемент в начало списка
	void reverse(); // Перевернуть список

private:
	ListNode<T>* head;
	size_t size;
};

template<typename T>
void LinkedList<T>::add_at_tail(T val) {
	// Создать новый экземляр ListNode или новый элемент списка
	ListNode<T>* newNode = new ListNode<T>(val, nullptr);

	if (head == nullptr) {
		head = newNode;
		++size;
		return;
	}
	// Двигаем указатель it до достижения последнего элемента списка
	ListNode<T>* it = head;
	while (it->next != nullptr)
		it = it->next;
	
	// Присваиеваем указателю на следующий элемент (next) текущего последнего элемента
	// адрес нового последнего элемента
	it->next = newNode;

	++size;
}

template<typename T>
void LinkedList<T>::delete_at_index(size_t index) {
	if (index >= size) {
		cout << "Index is larger than the size=" << size << "\n";
		return;
	}

	if (index == 0) {
		head = head->next;
		--size;
		return;
	}

	ListNode<T>* prev = head;
	ListNode<T>* curr = head->next;
	size_t pos = 1;
	
	while (pos < index) {
		prev = prev->next;
		curr = curr->next;
		++pos;
	}
	prev->next = curr->next;
	delete curr;

	--size;
}
template<typename T>
void LinkedList<T>::add_at_index(size_t index, T val) {
	if (index > size) {
		cout << "Index is larger than the size=" << size << "\n";
		return;
	}
	if (index == 0) {
		head = new ListNode<T>(val, head);
		return;
	}
	ListNode<T>* prev = head;
	ListNode<T>* curr = head->next;
	size_t pos = 1;
	
	while (pos < index) {
		prev = prev->next;
		curr = curr->next;
		++pos;
	}
	prev->next = new ListNode<T>(val, curr);
	++size;
}

template<typename T>
void LinkedList<T>::print_list() {
	if (size == 0) cout << "No elements in list.\n";
	else {
		ListNode<T>* cur = head;
		cout << "Elements: ";
		while (cur) { // == while (cur != nullptr)
			cout << cur->val << ' ';
			cur = cur->next;
		}
		cout << endl;
	}
}

template<typename T>
void LinkedList<T>::add_at_head(T val) {
	head = new ListNode<T>(val, head);
	++size;
}

template<typename T>
void LinkedList<T>::reverse() {
	if (size <= 1) return;
	ListNode<T>* prevEl = nullptr;
	ListNode<T>* curEl = head;
	ListNode<T>* nextEl = curEl->next;
	while (nextEl) {
		curEl->next = prevEl;
		prevEl = curEl;
		curEl = nextEl;
		nextEl = nextEl->next;
	}
	curEl->next = prevEl;
	head = curEl;
}

int main() {
	type arr[] = {1, 2, 3, 4, 5};
	LinkedList<type>* obj = new LinkedList<type>();
	obj->print_list();
	for (type val : arr) {
		obj->add_at_head(val);
	}
	obj->print_list();
	obj->reverse();
	cout << "Reversing\n";
	obj->print_list();

	cout << "Add at index 2\n";
	obj->add_at_index((size_t)2, 6);
	obj->print_list();

	return 0;
}