#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

std::vector<std::string> get_key_chars(char key) {
    std::vector<std::string> results;
    switch(key) {
    case '0':
        results.push_back("0");
        break;
    case '1':
        results.push_back("1");
        break;
    case '2':
        results.push_back("A");
        results.push_back("B");
        results.push_back("C");
        break;
    case '3':
        results.push_back("D");
        results.push_back("E");
        results.push_back("F");
        break;
    case '4':
        results.push_back("G");
        results.push_back("H");
        results.push_back("I");
        break;
    case '5':
        results.push_back("J");
        results.push_back("K");
        results.push_back("L");
        break;
    case '6':
        results.push_back("M");
        results.push_back("N");
        results.push_back("O");
        break;
    case '7':
        results.push_back("P");
        results.push_back("Q");
        results.push_back("R");
        results.push_back("S");
        break;
    case '8':
        results.push_back("T");
        results.push_back("U");
        results.push_back("V");
        break;
    case '9':
        results.push_back("W");
        results.push_back("X");
        results.push_back("Y");
        results.push_back("Z");
        break;
    }
    return results;
}


#endif // UTILS_H
