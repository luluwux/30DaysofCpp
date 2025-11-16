#include <iostream>
#include <string>
#include <fstream>

std::string parseInlineMarkdown(std::string text) {
    size_t p1, p2, p3, p4;
    while ((p1 = text.find("[")) != std::string::npos) {
        if ((p2 = text.find("]", p1)) == std::string::npos) break;
        if ((p3 = text.find("(", p2)) == std::string::npos || p3 != p2 + 1) break;
        if ((p4 = text.find(")", p3)) == std::string::npos) break;

        std::string linkText = text.substr(p1 + 1, p2 - p1 - 1);
        std::string url = text.substr(p3 + 1, p4 - p3 - 1);
        std::string htmlLink = "<a href=\"" + url + "\">" + linkText + "</a>";
        text.replace(p1, p4 - p1 + 1, htmlLink);
    }

    size_t pos1, pos2;
    while ((pos1 = text.find("**")) != std::string::npos) {
        if ((pos2 = text.find("**", pos1 + 2)) == std::string::npos) break;
        text.replace(pos2, 2, "</strong>");
        text.replace(pos1, 2, "<strong>");
    }

    while ((pos1 = text.find("*")) != std::string::npos) {
        if ((pos2 = text.find("*", pos1 + 1)) == std::string::npos) break;
        text.replace(pos2, 1, "</em>");
        text.replace(pos1, 1, "<em>");
    }
    
    return text;
}

std::string convertMarkdownLine(const std::string& rLine) {
    if (rLine.empty()) {
        return "";
    }

    if (rLine == "---" || rLine == "***" || rLine == "___") {
        return "<hr>";
    }

    size_t firstCharIndex = rLine.find_first_not_of(" \t");
    if (firstCharIndex == std::string::npos) {
        return "";
    }

    char firstChar = rLine[firstCharIndex];
    std::string iLine;
    std::string htmlTag;

    if (firstChar == '#') {
        int hLevel = 0;
        while (firstCharIndex + hLevel < rLine.length() && rLine[firstCharIndex + hLevel] == '#') {
            hLevel++;
        }

        if (hLevel > 0 && firstCharIndex + hLevel < rLine.length() && rLine[firstCharIndex + hLevel] == ' ') {
            iLine = rLine.substr(firstCharIndex + hLevel + 1);
            
            switch(hLevel) {
                case 1: htmlTag = "h1"; break;
                case 2: htmlTag = "h2"; break;
                case 3: htmlTag = "h3"; break;
                case 4: htmlTag = "h4"; break;
                case 5: htmlTag = "h5"; break;
                case 6: htmlTag = "h6"; break;
                default:
                    htmlTag = "p";
                    iLine = rLine.substr(firstCharIndex); 
                    break;
            }

            if (htmlTag != "p") {
                iLine = parseInlineMarkdown(iLine);
                return "<" + htmlTag + ">" + iLine + "</" + htmlTag + ">";
            }
        }
    }

    if (firstChar == '>') {
        iLine = rLine.substr(firstCharIndex + 1);
        if (iLine.length() > 0 && iLine[0] == ' ') {
            iLine = iLine.substr(1);
        }
        iLine = parseInlineMarkdown(iLine);
        return "<blockquote><p>" + iLine + "</p></blockquote>";
    }
    
    if (firstChar == '<') {
        return rLine;
    }

    iLine = rLine; 
    iLine = parseInlineMarkdown(iLine);
    return "<p>" + iLine + "</p>";
}

int main(int argc, char* argv[]) {
    std::string iFileName;
    std::string oFileName;

    if (argc == 3) {
        iFileName = argv[1];
        oFileName = argv[2];
    } else {
        std::cout << "Enter Input Markdown File Name: ";
        std::cin >> iFileName;
        std::cout << "Enter Output HTML File Name: ";
        std::cin >> oFileName;
    }

    std::ifstream iFile(iFileName); 
    std::ofstream oFile(oFileName);

    if (!iFile.is_open()) {
        std::cerr << "Error: Could not open input file -> " << iFileName << std::endl;
        return 1;
    }
    if (!oFile.is_open()) {
        std::cerr << "Error: Could not open output file -> " << oFileName << std::endl;
        iFile.close();
        return 1;
    }

    std::string rLine;
    while(std::getline(iFile, rLine)) {
        std::string convertedLine = convertMarkdownLine(rLine);
        
        if (rLine.empty()) {
            oFile << "\n";
        } else if (!convertedLine.empty()) {
            oFile << convertedLine << "\n";
        }
    }

    iFile.close(); 
    oFile.close(); 

    std::cout << "Success! File '" << iFileName << "' converted to '" << oFileName << "'" << std::endl;

    return 0; 
}