#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Trims whitespace from the beginning and end of a string.
 */

std::string trim(const std::string& str) {
    const char* whitespace = " \t\n\r\f\v";

    size_t first = str.find_first_not_of(whitespace);

    if (std::string::npos == first) {
        return "";
    }

    size_t last = str.find_last_not_of(whitespace);

    return str.substr(first, (last - first + 1));
}

int main(){
    int codeCounter = 0;
    int commentCounter = 0;
    int blankLineCounter = 0;
    
    std::string readLine;
    std::string fileName;
    
    std::cout << "Please enter the file name to read. Ex: main.cpp" << std::endl;
    std::cin >> fileName;
    std::ifstream fileReader(fileName);

    if (!fileReader.is_open()) {
        std::cerr << "Error: Could not open file -> " << fileName << std::endl;
        return 1;
    }

    bool inBlockComment = false;

    while (std::getline(fileReader, readLine)) {
        std::string cleanLine = trim(readLine);

        if (inBlockComment) {
            commentCounter++;
            std::cout << commentCounter << ". Comment Line (Inside block)" << std::endl;
            if (cleanLine.find("*/") != std::string::npos) {
                inBlockComment = false;
            }
        } else {
            if(cleanLine.empty()){
                blankLineCounter++; 
                std::cout << blankLineCounter << ". Blank Line" << std::endl;
            } else if (cleanLine.find("//") == 0) {
                commentCounter++;
                std::cout << commentCounter << ". Comment Line (Single)" << std::endl;
            } else if (cleanLine.find("/*") == 0) {
                commentCounter++;
                std::cout << commentCounter << ". Comment Line (Block start)" << std::endl;
                if (cleanLine.find("*/") == std::string::npos) {
                    inBlockComment = true;
                }
            } else {
                codeCounter++;
                std::cout << codeCounter << ". Code Line" << std::endl;
            }
        }
    }
    
    fileReader.close();
    
    std::cout << "\n--- Report ---" << std::endl;
    std::cout << "Total Code Lines: " << codeCounter << std::endl;
    std::cout << "Total Blank Lines: " << blankLineCounter << std::endl;
    std::cout << "Total Comment Lines: " << commentCounter << std::endl;

    return 0;
}