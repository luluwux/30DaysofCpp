#include <iostream>
#include <random>
using namespace std;

int main() {

    /* 
    Rastgele sayı üretimi için gerekli ayarlar
    */
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    
    int estimateNumber = dis(gen);
    int userNumber;

cout << "1 ile 100 arasında bir sayı tahmin edin: " << endl;
    while(userNumber != estimateNumber) {
        cout << "Tahmininiz: ";
        cin >> userNumber;

        if(userNumber < estimateNumber) {
            cout << "Daha büyük bir sayı tahmin et!" << endl;
        } else if (userNumber > estimateNumber) {
            cout << "Daha küçük bir sayı tahmin et!" << endl;
        } else {
            cout << "Tebrikler! Doğru tahmin ettiniz! Sayı: " << estimateNumber << endl;
        }
    }

    return 0;
}