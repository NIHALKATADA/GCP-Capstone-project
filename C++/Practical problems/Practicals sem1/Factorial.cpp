#include <iostream>
using namespace std;

int factorialRecursive(int n) {
    if(n <= 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

int factorialIterative(int n) {
    int result = 1;
    for(int i = 1; i <= n; i++)
        result *= i;
    return result;
}

int fibonacciRecursive(int n) {
    if(n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciIterative(int n) {
    if(n <= 1)
        return n;
    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial Recursive: " << factorialRecursive(n) << endl;
    cout << "Factorial Iterative: " << factorialIterative(n) << endl;
    cout << "Fibonacci Recursive: " << fibonacciRecursive(n) << endl;
    cout << "Fibonacci Iterative: " << fibonacciIterative(n) << endl;
    return 0;
}