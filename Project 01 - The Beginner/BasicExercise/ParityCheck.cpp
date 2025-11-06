#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: "; cin >> number;

    if (number % 2 == 0) {
        cout << "Number is Even" << endl; 
    } else {
        cout << "Number is Odd" << endl;

    }
}