#include <iostream>
using namespace std;
int findLargest(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cout << "--- Math Operations ---\n";
    cout << "Largest of 15, 42, 8 is: " << findLargest(15, 42, 8) << "\n";
    cout << "GCD of 56 and 98 is: " << gcd(56, 98) << "\n";

    return 0;
}