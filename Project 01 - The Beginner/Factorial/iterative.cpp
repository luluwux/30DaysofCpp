#include <iostream>
using namespace std;
// Iterative function to calculate factorial
int main() {
    int number; 
    cout << "Enter a non-negative integer: ";
    cin >> number;

    unsigned long long factorial = 1;
    
    for (int i = 1; i <= number; i++){
       factorial = factorial * i;
       cout << "Factorial of " << i << " is " << factorial << endl;
    }

}