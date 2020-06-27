#include <iostream>
#include <string>

using namespace std;

string parseTernary(string str) {
    while (str.size() > 1) {
        int pos = str.find_last_of('?');
        str = str.substr(0, pos - 1) + ((str[pos - 1] == 'T') ? str[pos + 1] : str[pos + 3]) + str.substr(pos + 4);
    }
    return str;
}