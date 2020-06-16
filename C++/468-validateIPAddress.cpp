#include <iostream>
#include <string>

using namespace std;

string validIPAddress(string IP) {
    stringstream ss(IP);
    string t;
    int count = 0;

    if (IP.find(":") == string::npos) {
        while (getline(ss, t, '.')) {
            count++;
            if (count > 4 || t.length() == 0 || t.length() > 3 || (t.length() > 1 && t[0] == 0)) return "Neither";
            for (int i = 0; i < t.size(); i++) {
                if (t[i] < '0' || t[i] > '9') return "Neither";
            }
            int val = stoi(t);
            if (val > 255 || val < 0) return "Neither";
        }
        return (count == 4 && IP.back() != '.') ? "IPv4" : "Neither"; 
    } else {
        while (getline(ss, t, ':')) {
            count++;
            if (count > 8 || t.length() > 4 || t.length() == 0) return "Neither";
            for (int i = 0; i < t.size(); i++) {
                if (!(t[i] >= '0' && t[i] <= '9') && !(t[i] >= 'a' && t[i] <= 'f') && !(t[i] >= 'A' && t[i] <= 'F')) return "Neither";
            }
        }
        return (count == 8 && IP.back() != ':') ? "IPv6" : "Neither";
    }
    return "Neither";
}