#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: "; cin >> number;

    if(number <= 0) {
        cout << "The number is not negative";
    } else {
        cout << "The number is negative";
    } 
}