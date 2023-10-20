#include <iostream>

using namespace std;

void TowerOfHanoi(int n, int source, int auxiliary, int target) {
    if (n == 1) {
        cout << "1 " << source << " " << target << endl;
        return;
    }

    TowerOfHanoi(n - 1, source, target, auxiliary);
    cout << n << " " << source << " " << target << endl;
    TowerOfHanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n;
    cin >> n;
    
    TowerOfHanoi(n, 1, 2, 3);

    return 0;
}