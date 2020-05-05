#include <iostream>
#include <string>
#include <climits>

using namespace std;

int myAtoi(string str) {
    int length = str.size();
    int i = 0;
    long num = 0;
    bool isNeg = false;

    while (i < length && str[i] == ' ') {
        i++;
    }

    if (i < length && str[i] == '-') {
        isNeg = true;
        i++;
    } else if (i < length && str[i] == '+') {
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + str[i] - '0';
        i++;
        if (num > INT_MAX) {
            break;
        }
    }
    if (num > INT_MAX) {
        if (isNeg) {
            return INT_MIN;
        } else {
            return INT_MAX;
        }
    }

    if (isNeg) {
        return num * -1;
    } else {
        return num;
    }
} 

int myAtoiCheat(string str) {
    while (str.size() && isspace(str.front())) {
        str.erase(str.begin());
    }
    try {
        return stoi(str);
    } catch (out_of_range& e) {
        if (str[0] == '-') {
            return INT_MIN;
        } 
        return INT_MAX;
    } catch (invalid_argument& e) {
        return 0;
    }
}

int main() {

    string str = "words and 987";
    cout << myAtoiCheat(str) << endl;

    return 0;
}