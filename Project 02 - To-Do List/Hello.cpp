#include <iostream>

using namespace std; // Her seferinde std:: yazarak başlamamak için kullanılır.

int main()
{
    cout << "Hello World" << endl;

    /*
    cout << "Hello World \n"
    cout << "Hellow World" << endl;
    İki kullanımda aynı amaca(Konsolda alt satıra geçer) hizmet eder.
    */

    std::cout << "Merhaba Dünya!";


    // Numbers yazdırma
    cout << 5 << endl; // Konsola Number olarak 5 yazdırır.

    cout << 5 + 10 << endl; // 15
    cout << 5 * 10 << endl; // 50

    return 0;
}
