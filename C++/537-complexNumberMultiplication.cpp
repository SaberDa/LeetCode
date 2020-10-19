#include <string>

using namespace std;

pair<int, int> sep(string s) {
    auto sp = s.find('+');
    return make_pair(stoi(s.substr(0, sp)), stoi(s.substr(sp + 1, s.size() - sp - 2)));
}

string complexNumberMultiply(string a, string b) {
    auto m = sep(a), n = sep(b);
    string part1 = to_string(m.first * n.first - m.second * n.second);
    string part2 = to_string(m.second * n.first + m.first * n.second);
    return part1 + "+" + part2 + "i";
}