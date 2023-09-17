#include <iostream>
#include <random>
#include <cstring>

using namespace std;

// 
void resize(int* &arr, int& size, int* ptr, int num, int index) {
    // Вводим новый размер
    int newSize = size + num, i;
    int* newArr = new int[newSize];
    // Запись в новый массив В)
    memcpy(newArr, arr, index * sizeof(int));
    for(i = 0; i < num; ++i) newArr[index + i] = ptr[i];
    for(i = index; i < size; ++i) newArr[i + num] = arr[i];
    // Очищаем память от мусора
    delete [] arr;
    // Перезапись адреса
    arr = newArr;
    size = newSize;
}

int main() {
    int num = 5;
    int size = 10;
    int insertIndex;
    int *newArr = new int[num];
    int *arr = new int[size];

    for(int i = 0; i < size; ++i) arr[i] = rand() % 100;
    for(int i = 0; i < size; ++i) cout << arr[i] << ' ';
    cout << endl << endl;


    for(int i = 0; i < num; ++i) newArr[i] = rand() % 100;
    for(int i = 0; i < num; ++i) cout << newArr[i] << ' ';
    cout << endl << endl;

    cout << "После какого элемента добавить новый массив: ";
    cin >> insertIndex;

    resize(arr, size, newArr, num, insertIndex);
    
    for(int i = 0; i < size; ++i) cout << arr[i] << ' ';
    return 0;
}