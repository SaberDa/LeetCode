#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> toDigit(int num) {
    vector<int> res;
    while (num) {
        res.push_back(num % 10);
        num = num / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int toInt(vector<int>& nums) {
    int res = 0;
    for (auto i : nums) {
        res = res * 10 + i;
    }
    return res;
}

int maxumunSwap(int num) {
    if (num < 10) {
        return num;
    }

    vector<int> dic = toDigit(num);
    int first = 1;
    while (first < dic.size() && dic[first] <= dic[first - 1]) {
        first++;
    }
    if (first == dic.size()) {
        return num;
    }

    int cur = first;
    for (int i = first; i < dic.size(); i++) {
        if (dic[i] >= dic[cur]) {
            cur = i;
        }
    }

    int second = first - 1;
    while (second - 1 >= 0 && dic[second - 1] < dic[cur]) {
        second--;
    }
    swap(dic[cur], dic[second]);

    return toInt(dic);
}

int maximumSwap2(int num) {
    if (num < 10) {
        return num;
    }
    string digits = to_string(num);
    int cur = 1;
    while (cur < digits.length() && digits[cur] <= digits[cur - 1]) {
        cur++;
    }
    if (cur == digits.length()) {
        return num;
    }
    int first = cur;
    for (int i = first; i < digits.size(); i++) {
        if (digits[i] >= digits[first]) {
            first = i;
        }
    }
    int second = cur - 1;
    while (second - 1 >= 0 && digits[second - 1] < digits[first]) {
        second--;
    }
    swap(digits[first], digits[second]);

    return stoi(digits);    
}

int maximumSwap3(int num) {
    if (num < 10) {
        return num;
    }
    string digits = to_string(num);

    auto cur = is_sorted_until(digits.begin(), digits.end(), greater<char>());

    if (cur == digits.end()) {
        return num;
    }

    auto first = max_element(cur, digits.end(), less_equal<char>());
    auto second = upper_bound(digits.begin(), cur, *first, greater<char>());

    iter_swap(first, second);
    return stoi(digits);
}