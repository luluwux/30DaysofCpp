#include <iostream>
using namespace std;

int main() {
    int numberOne, numberTwo, numberSave;
    cout << "Enter the first number: "; cin >> numberOne;
    cout << "Enter the second number: "; cin >> numberTwo;

    numberOne = numberSave;
    numberOne = numberTwo;
    numberTwo = numberSave;

    cout << "Number One: " << numberOne << " " << "Number Two: " << numberTwo << endl;

}