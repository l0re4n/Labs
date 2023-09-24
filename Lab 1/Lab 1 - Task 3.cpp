#include <iostream>
#include <random>

using namespace std;

int main() {
    int len_n, len_m, i, j, count = 0, memo = 33;
    cin >> len_m;
    cin >> len_n;
    int *m = new int[len_m];
    int *n = new int[len_n];
    int *res = new int[len_m > len_n ? len_m : len_n];
    for(i = 0; i < len_m; ++i) m[i] = rand() % 1500;
    for(i = 0; i < len_n; ++i) n[i] = rand() % 1000;
    // -----------------------------------------------------------
    long long int memoM[memo] = {0}; 
    long long int memoN[memo] = {0};
    const long long one = 1;
    for(i = 0; i < len_m; ++i) memoM[m[i] / 64] |= one << (m[i] % 64);
    for(i = 0; i < len_n; ++i) memoN[n[i] / 64] |= one << (n[i] % 64);
    long long int memoR[memo];
    for(i = 0; i < memo; ++i) memoR[i] = memoM[i] ^ memoN[i];
    // ----------------------------------------------------------
    for(i = 0; i < len_m; ++i) {
        cout << m[i] << ' ';
    }
    cout << endl;
    cout << endl;
    for(i = 0; i < len_n; ++i) {
        cout << n[i] << ' ';
    }
    cout << endl;
    cout << endl;
    // -----------------------------------------------------------
    for(i = 0; i < memo; ++i) {
        for(j = 0; j < 64; ++j) {
            if(memoR[i] & 1) res[count++] = i * 64 + j;
            memoR[i] >>= 1;
        }
    }
    for(i = 0; i < count; ++i) {
        cout << res[i] << ' ';
    }
    return 0;
}