#include <string>
#include <sstream>

using namespace std;

string toGoatLatin(string S) {
    istringstream is(S);
    ostringstream os;
    string V = "aeiouAEIOU", s, a = "a";
    while (is >> s) {
        if (V.find(s[0]) == string::npos) {
            os << s.substr(1) << s[0];
        } else {
            os << s;
        }
        os << "ma" << a << " ";
        a.push_back('a');
    }
    string res = os.str();
    res.pop_back();
    return res;
}