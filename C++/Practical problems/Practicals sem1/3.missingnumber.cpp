#include <iostream>
using namespace std;

int main() 
{
    int nums[] = {3, 0, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int i = 0; i < n; i++) 
    {
        actualSum += nums[i];
    }
    cout << "The missing number is: " << (expectedSum - actualSum) << endl;
    return 0;
}