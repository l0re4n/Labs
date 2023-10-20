#include <iostream>

using namespace std;

void generate(int N, int K, int* chain, int current) {
    if (current == N) {
        for (int i = 0; i < N; i++) {
            cout << chain[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int xi = 1; xi <= K; xi++) {
        chain[current] = xi;
        generate(N, K, chain, current + 1);
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    int* chain = new int[N];
    generate(N, K, chain, 0);
    delete[] chain;
    return 0;
}