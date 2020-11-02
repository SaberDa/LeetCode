#include <vector>
#include <unordered_set>

using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> table{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> s;
    for (string x : words) {
        string temp = "";
        for (auto c : x) temp += table[c - 'a'];
        s.insert(temp);
    }
    return s.size();
}