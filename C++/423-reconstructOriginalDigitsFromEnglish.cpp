#include <vector>
#include <string>

using namespace std;

string originalDigits(string s) {
    vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
    vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    vector<int> distinct_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
    vector<int> counts(26, 0);
    string res;
    for (auto c : s) counts[c - 'a']++;
    for (int i = 0; i < 10; i++) {
        int count = counts[distinct_char[i] - 'a'];
        for (int j = 0; j < words[i].size(); j++) {
            counts[words[i][j] - 'a'] -= count;
        }
        while (count--) res += to_string(nums[i]);
    }
    sort(res.begin(), res.end());
    return res;
}