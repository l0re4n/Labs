#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long long num1, num2;

    cin >> num1 >> num2;

    if (num1 <= 0 || num2 <= 0) {
        cout << "Numbers should be natural" << endl;
    } else {
        long long result = gcd(num1, num2);
        cout << result;
    }

    return 0;
}
