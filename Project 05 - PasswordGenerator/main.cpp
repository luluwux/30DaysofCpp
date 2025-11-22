#include <iostream>
#include <string>
#include <vector>
#include <random>

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc);

    int pLength = 10;
    bool isNumber, isSymbol = false;

    for (size_t i = 1; i < args.size(); ++i) {
        if(args[i] == "-l") {
            if(i + 1 < args.size()) {
                pLength = std::stoi(args[i + 1]);
            } else {
                std::cout << "Err: -l den sonra sayuı gir" << std::endl;
                return 1;
            }
        } else if(args[i] == "-n") {
            isNumber = true;
        } else if(args[i] == "-s") {
            isSymbol = true; 
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::string cPool = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string nPool = "0123456789";
    std::string sPool = "!@#$%^&*()_+-=[]{}";

    if(isNumber) {
        cPool += nPool;
    }
    if(isSymbol) {
        cPool += sPool;
    }

    std::uniform_int_distribution<> dis(0, cPool.size() - 1);
    
    std::string newPassword = "";
    for(int i = 0; i < pLength; ++i) {
        int randomIndex = dis(gen);
        newPassword += cPool[randomIndex];
    }

    std::cout << "New Pssword: " << newPassword << std::endl;

    system("pause");
    return 0;
}































