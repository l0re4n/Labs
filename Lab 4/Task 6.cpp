#include <iostream>

using namespace std;

bool canReachN(int current, int N) {
    if (current == N) {
        return true;
    }
    if (current > N) {
        return false;
    }

    return canReachN(current + 3, N) || canReachN(current + 5, N);
}

int main() {
    int N;
    std::cin >> N;

    if (canReachN(1, N)) {
        std::cout << "YES" << endl;
    } else {
        std::cout << "NO" << endl;
    }
    return 0;
}