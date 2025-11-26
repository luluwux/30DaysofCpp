#include <iostream>
#include <thread> 
#include <chrono> 
#include <iomanip>

int main() {
    int totalTime = 1500;

    while (totalTime > 0)
    {
        int rMinutes = totalTime / 60;
        int rSeconds = totalTime % 60;

        std::cout 
          << std::setw(2) << std::setfill('0') << rMinutes 
          << ":" 
          << std::setw(2) << std::setfill('0') << rSeconds 
          << "\r" << std::flush;

        // 1 Saniyeliğine durdur ve ardından devam ettir
        std::this_thread::sleep_for(std::chrono::seconds(1));
        totalTime--;
    }

    std::cout << std::setw(2) << std::setfill('0') << 0 << ":" 
              << std::setw(2) << std::setfill('0') << 0 << std::endl; // Son kez 00:00 yaz ve alt satıra geç
    std::cout << "Time is up!" << std::endl;

    std::cout << '\a';
    
}
