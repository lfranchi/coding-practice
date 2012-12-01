#include "strings.h"
#include "utils.h"

#include <set>
#include <iostream>

using namespace std;

vector<string> permute(const string &str) {
    vector<string> result;
    if(str.size() == 1)
        result.push_back(str);
    else {
        for(int i = 0; i < str.size(); i++) {
            string perm;
            for(int k = 0; k < str.size(); k++) {
                if(k != i)
                    perm.push_back(str.at(k));
            }
            vector<string> perms = permute(perm);
            for(int j = 0; j < perms.size(); j++) {
                result.push_back(str[i] + perms[j]);
            }
        }
    }
    return result;
}

set<string> all_perms(const string& str) {
    set<string> res;
    if(str.length() == 1)
        res.insert(str);
    else {
        for(int i = 0; i < str.length(); i++) {
            string perm;
            for(int k = 0; k < str.length(); k++) {
                if(k != i) perm.push_back(str[k]);
            }
            set<string> r = all_perms(perm);
            for(auto a : r) {
                res.insert(a);
                res.insert(str[i] + a);
            }
        }
    }
    return res;
}

bool is_palindrome(const string &str) {
    int left = 0;
    int right = str.size() - 1;
    while(true) {
        if(str[left] != str[right])
            return false;
        do { left++; } while(left < str.size() - 1 && str[left] == ' ');
        do { right--; } while(right >= 0 && str[right] == ' ');
        if(left >= right)
            break;
    }
    return true;
}

vector<string> telephone_words(const string& number) {
    vector<string> result;
    if(number.size() == 1)
        result = get_key_chars(number[0]);
    else {
        const vector<string> left = get_key_chars(number[0]);
        const vector<string> right = telephone_words(number.substr(1, number.size() - 1));
        for(auto l : left) {
            for(auto r : right) {
                result.push_back(l + r);
            }
        }
    }
    return result;
}

void print_telephone_words(const string &number)
{
    const vector<string> words = telephone_words(number);
    for(auto word : words)
        cout << word << " ";
    cout << endl;
}

void run_strings() {
    string to_permute = "t runs";
    cout << "Permuted: '" << to_permute << "' to ";
    vector<string> perms = permute(to_permute);
    for(auto str : perms) {
        cout << str << ", ";
    }
    cout << endl;

    string palindrome = "not a palindrome";
    string palindrom_yes = "why hellow palindromeemordnilap wolleh yhw";
    cout << "this is not a palindrom: '" << palindrome << "'? " << is_palindrome(palindrome) << endl;
    cout << "this is a palindrome indeed: '" << palindrom_yes << "'? " << is_palindrome(palindrom_yes) << endl;

    string number = "2363537";
    const vector<string> words = telephone_words(number);
    cout << "First telephone word for " << number << " is " << words.front() << " number in list is " << words.size() << endl;
    cout << "Checking tht the list includes BENEKES: " << (find(words.begin(), words.end(), "BENEKES") != words.end()) << endl;

    cout << "ALL PERMUTATIONS of " << to_permute << " are: ";
    set<string> aperms = all_perms(to_permute);
    for(auto str : aperms) {
        cout << str << ", ";
    }
    cout << endl;
    cout << "len of 10 items: " << all_perms("asdfpghejk").size() << endl;
}
