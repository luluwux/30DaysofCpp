#include <iostream>
using namespace std;

int main() {
    int numberOne, numberTwo;
    cout << "Enter the first number: "; cin >> numberOne;
    cout << "Enter the second number: "; cin >> numberTwo;

    if(numberOne % numberTwo == 0) {
        cout << "Is Exactly Divisible" << endl;
    } else {
        cout << "Is Not Exactly Divisible" << endl;
    }
}