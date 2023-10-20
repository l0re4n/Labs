#include <iostream>

using namespace std;

long long Fibonacci(int n, long long a = 0, long long b = 1) {
    if (n == 0) {
        return a;
    }
    if (n == 1) {
        return b;
    }
    return Fibonacci(n - 1, b, a + b);
}


int main() {
    int N;
    cin >> N;

    if (N < 0) {
        cout << "N should be negative";
    }

    long long result = Fibonacci(N);

    cout << result;
}