#include "Helper.h"

#include <iostream>
#include <limits>

void printMenu() {
    std::cout << "\n--- MENU ---" << std::endl;
    std::cout << "1. Gorev Ekle" << std::endl;
    std::cout << "2. Gorev Sil" << std::endl;
    std::cout << "3. Gorevi Tamamlandi Isaretle" << std::endl;
    std::cout << "4. Gorevleri Listele" << std::endl;
    std::cout << "5. Cikis" << std::endl;
    std::cout << "Seciminiz: ";
};
void clearMenu() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int getUserInput(int maxOption) {
    int input;
    while (true)
    {
       std::cout << "\nLutfen 1 ile " << maxOption << " arasinda bir secim yapin: ";
       
        if (std::cin >> input && input >= 1 && input <= maxOption) {
            break; 
        } else {
          
            std::cout << "Gecersiz giris. Lutfen tekrar deneyin." << std::endl;
            
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } 
    return input;
};

