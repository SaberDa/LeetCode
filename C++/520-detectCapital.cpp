#include <string>

using namespace std;

bool detectCapitalUse(string word) {
    if (word.empty()) return false;
    if (word.size() == 1) return true;
    bool lower = true, upper = true;
    for (int i = 1; i < word.size(); i++) {
        if (isupper(word[i])) lower = false;
        else upper = false;
    }
    return lower || (upper && isupper(word[0]));
}