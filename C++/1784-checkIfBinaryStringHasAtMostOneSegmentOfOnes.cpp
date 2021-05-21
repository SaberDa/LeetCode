class Solution {
public:
    bool checkOnesSegment(string s) {
        if (s.find('0') == string::npos) return true;
        int index = s.find('0');
        s = s.substr(index);
        if (s.find('1') != string::npos) return false;
        else return true;
    }
};