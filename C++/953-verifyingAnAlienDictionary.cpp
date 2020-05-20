#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> mp;
    for (int i = 0; i < order.length(); i++) {
        mp[order[i]] = i;
    }
    for (int k = 1; k < words.size(); k++) {
        string a = words[k-1];
        string b = words[k];
        if (a == b) {
            continue;
        }
        int i = 0;
        int j = 0;
        int flag = 0;
        int n = a.length();
        int m = b.length();
        while (i < n && j < m) {
            if (mp[a[i]] < mp[b[j]]) {
                flag = 1;
                break;
            }
            if (mp[a[i]] > mp[b[j]]) {
                return false;
            }
            i++;
            j++;
        }
        if (i == n && j < m) {
            flag = 1;
        }
        if (flag == 0) {
            return false;
        }
    }
    return true;
}