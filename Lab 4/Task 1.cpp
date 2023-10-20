#include <iostream>
#include <string>

using namespace std;

bool isEnglish(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void addStar(string& str, size_t index) {
    if (index >= str.length() - 1) {    
        return;
    }

    if (isEnglish(str[index]) && isEnglish(str[index + 1])) {
        str.insert(index + 1, 1, '*');
    }

    addStar(str, index + 1);
}

int main() {
    string s;
    cin >> s;
    
    addStar(s, 0);

    cout << s;
}