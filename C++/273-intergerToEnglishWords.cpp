#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> lessThen20{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};


string helper(int num) {
    string res;
    if (num >= 100) {
        int qua = num / 100;
        res += lessThen20[qua] + " Hundred";
        num = num % 100;
        if (num > 0) {
            res += " ";
        }
    }
    if (num < 100 && num >= 20) {
        int qua = num / 10;
        res += tens[qua];
        num = num % 10;
        if (num > 0) {
            res += " ";
        }
    }
    if (num <= 19) {
        res += lessThen20[num];
    }
    return res;
}

string numberToWords(int num) {
    string res;
    if (num == 0) {
        return "Zero";
    }
    if (num >= 1000000000) {
        int qua = num / 1000000000;
        res += lessThen20[qua] + " Billion";
        num = num % 1000000000;
        if (num > 0) {
            res += " ";
        }
    }
    if (num >= 1000000) {
        int qua = num / 1000000;
        res += helper(qua) + " Million";
        num = num % 1000000;
        if (num > 0) {
            res += " ";
        }
    }
    if (num >= 1000) {
        int qua = num / 1000;
        res += helper(qua) + " Thousand";
        num = num % 1000;
        if (num > 0) {
            res += " ";
        }
    }
    res += helper(num);
    return res;
}