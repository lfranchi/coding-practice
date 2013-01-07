#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "linkedlists.h"
#include "trees_heaps.h"
#include "strings.h"
#include "dynamic_programming.h"

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

double sqrt_of_double(double num)
{
    double previous = 0.0;
    double approx = num;
    do {
        previous = approx;
        approx = (0.5)*(approx + (num/approx));

    } while( fabs( (approx * approx) - num ) > 0.0000000000001 );
//    } while( fabs(previous - approx) < 0.000000001 );

    return approx;
}

vector<int> merge(vector<vector<int> > arrays) {
    int len = 0;
    for(auto v : arrays)
        len += v.size();
    vector<int> result(len);
    int cur = 0;

    vector<vector<int>::iterator> iters(arrays.size());
    for(int i = 0; i < arrays.size(); i++) {
        iters[i] = arrays[i].begin();
    }

    while(true) {
        int smallest = INT_MAX; int smallest_idx;
        for(int i = 0; i < iters.size(); i++) {
            auto iter = iters[i];
            if(iter != arrays[i].end() && *iter < smallest) {
                smallest = *iter;
                smallest_idx = i;
            }
        }
        if (smallest == INT_MAX) // no more
            break;

        result[cur] = smallest;
        cur++;

        iters[smallest_idx] = ++iters[smallest_idx];
    }

    return result;
}

int main(int argc, char *argv[])
{
    cout << "fib of 10: " << fib(10) << endl;
    cout << "Sum of lines in file:" << sum("/Users/leo/Documents/hackerschool/coding-practice/test.txt") << endl;
//    run_linked_lists();
//    do_trees();
//    do_dp();
//    run_strings();

    cout << "Square root of 2.532 should be: 1.591225942, our approx is: " << sqrt_of_double(2.532) << endl;

    vector<int> one, two, three;
    one.push_back(1);
    one.push_back(3);
    one.push_back(5);
    two.push_back(2);
    two.push_back(4);
    two.push_back(6);
    three.push_back(3);
    three.push_back(5);
    three.push_back(7);
    vector<vector<int> > tomerge;
    tomerge.push_back(one);
    tomerge.push_back(two);
    tomerge.push_back(three);
    auto result = merge(tomerge);
    cout << "Merged arrays! Should be sorted: ";
    for(auto i : result) cout << i << " ";
    cout << endl;

    return 0;
}
