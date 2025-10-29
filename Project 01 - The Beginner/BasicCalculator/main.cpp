#include <iostream>
using namespace std;

int main() {

    int operation;
    double numOne, numTwo; 

    cout << "Select the operation you want to perform:" << endl;
    cout << "1: Addition" << endl;
    cout << "2: Subtraction" << endl;
    cout << "3: Multiplication" << endl;
    cout << "4: Division" << endl;
    cout << "Your choice (1-4): ";
    
    cin >> operation;

    cout << "Enter the first number: ";
    cin >> numOne; 
    cout << "Enter the second number: ";
    cin >> numTwo; 

    switch (operation) {
        case 1:
            cout << "Answer: " << numOne + numTwo << endl; 
            break;
        case 2:
            cout << "Answer: " << numOne - numTwo << endl; 
            break;
        case 3:
            cout << "Answer: " << numOne * numTwo << endl; 
            break;
        case 4:
            if (numTwo != 0) { 
                cout << "Answer: " << numOne / numTwo << endl;
            } else {
                cout << "Error: Cannot divide by zero!" << endl;
            }
            break;
        default:
            cout << "Invalid operation selected." << endl;
            break;
    }

    return 0;
}