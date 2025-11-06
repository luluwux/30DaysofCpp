#include <iostream>
using namespace std;

int main() {
    int number; 
    cout << "Enter a number: "; cin >> number;

    if(number > 0) {
        cout << "The number is pozitive";
    } else if(number < 0) {
        cout << "The number is negative";
    } else {
        cout << "The number is 0";
    }
}