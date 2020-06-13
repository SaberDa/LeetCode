#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool helper(unordered_set<char>& set, char ch) {
    if (set.find(tolower(ch)) != set.end()) return true;
    else return false;
}

vector<string> findWords(vector<string>& words) {
    unordered_set<char> set1{'q','w','e','r','t','y','u','i','o','p'};
    unordered_set<char> set2{'a','s','d','f','g','h','j','k','l'};
    unordered_set<char> set3{'z','x','c','v','b','n','m'};
    vector<string> res;
    if (words.empty()) return res;
    for (auto word : words) {
        bool flag = true;
        unordered_set<char> set;
        if (helper(set1, word[0])) set = set1;
        else if (helper(set2, word[0])) set = set2;
        else set = set3;
        for (auto c : word) {
            if (set.find(tolower(c)) == set.end()) {
                flag = false;
                break;
            }
        }
        if (flag) res.push_back(word);
    }
    return res;
}