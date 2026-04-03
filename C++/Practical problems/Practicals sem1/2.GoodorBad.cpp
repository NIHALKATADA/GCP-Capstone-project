#include <iostream>
#include <string>
using namespace std;
int main() {
    string s = "schoool"; // You can change this input
    int vCount = 0;
    int cCount = 0;
    bool isBad = false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vCount++;
            cCount = 0;
        } else {
            cCount++;
            vCount = 0;
        }

        if (vCount == 3 || cCount == 5) {
            isBad = true;
            break;
        }
    }
    if (isBad) {
        cout << "Bad" << endl;
    } else {
        cout << "Good" << endl;
    }
    return 0;
}