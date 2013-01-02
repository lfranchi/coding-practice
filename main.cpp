#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "linkedlists.h"
#include "trees_heaps.h"
#include "strings.h"

using namespace std;

string reverse(const string& str) {
    string v;
    for(int i = str.length() - 1; i >= 0; i--) {
        v.push_back(str.at(i));
    }

    return v;
}

void reverse_inplace(string& str) {
    char tmp;
    for(int i = 0; i < str.length()/2; i++) {
        tmp = str[i];
        str[i] = str[str.length() - i - 1];
        str[str.length() - i - 1] = tmp;
    }
}

int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

int sum(const string& filename) {
    ifstream file;
    file.open(filename.c_str());
    if (!file.is_open()) return -1;
    int max = 0, cur = 0;
    string line;
    while (file.good()) {
        getline(file, line);
        cur = strtol(line.c_str(), NULL, 10);
        max += cur;
    }

    file.close();
    return max;
}

int main(int argc, char *argv[])
{
    cout << "fib of 10: " << fib(10) << endl;
    cout << "Sum of lines in file:" << sum("/Users/leo/Documents/hackerschool/coding-practice/test.txt") << endl;
//    run_linked_lists();
    do_trees();
//    run_strings();
    return 0;
}
