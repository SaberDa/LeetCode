#include <vector>
#include <string>

using namespace std;

bool validWordAbbreviation(string word, string abbr) {
    int i = 0;
    for (int j = 0; j < abbr.size(); ) {
        if (isalpha(abbr[j])) {
            if (abbr[j] == word[i]) i++, j++;
            else return false;
        } else {
            if (abbr[j] == '0') return false;
            int numStart = j;
            while (j < abbr.size() && isdigit(abbr[j])) j++;
            i = i + stoi(abbr.substr(numStart, j - numStart));
            if (j == abbr.size()) return i == word.size();
            if (i >= word.size()) return false;
        }
    }
    return true;
}