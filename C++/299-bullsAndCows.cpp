#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string getHint(string secret, string guess) {
    if (secret.empty() || guess.empty()) return "";
    unordered_map<char, int> mpa;
    unordered_map<char, int> mpb;
    int a = 0, b = 0;
    for (int i = 0; i < secret.size(); i++) {
        mpa[secret[i]]++;
        mpb[guess[i]]++;
        if (secret[i] == guess[i]) a++;
    }
    for (auto it : mpa) {
        if (mpb.count(it.first)) b += min(it.second, mpb[it.first]);
    }
    b -= a;
    return to_string(a) + "A" + to_string(b) + "B";
}